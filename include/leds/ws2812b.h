#pragma once

#include <avr/util.h>
#include <hal/port.h>
#include <array>
#include <cstdint>

#include <leds/colors.h>

// based on https://github.com/cpldcpu/light_ws2812

namespace BMCPP {
    template <typename Pin, auto led_count>
    struct WS2812B final {
        WS2812B() = delete;
        static void show(const std::array<GRBColor, led_count> &colors);
        static void clear(){
            show(std::array<GRBColor, led_count>{});
        }
    private:
        using Port = typename Pin::port_type;

        static constexpr long int frequency_khz = F_CPU / 1000;

        static constexpr unsigned int low_voltage_time = 350;
        static constexpr unsigned int high_voltage_time = 900;
        static constexpr unsigned int period_time = low_voltage_time + high_voltage_time;

        static constexpr unsigned int fixed_low_cycles = 2;
        static constexpr unsigned int fixed_high_cycles = 4;
        static constexpr unsigned int fixed_total_cycles = 8;

        static constexpr long int zero_cycles = ((frequency_khz * low_voltage_time) / 1'000'000);
        static constexpr long int one_cycles = ((frequency_khz * high_voltage_time + 500'000) / 1'000'000);
        static constexpr long int total_cycles = ((frequency_khz * period_time + 500'000) / 1'000'000);

        static constexpr long int rising_falling_nops_count = zero_cycles - fixed_low_cycles;
        static constexpr long int falling_rising_nops_count = one_cycles - fixed_high_cycles - rising_falling_nops_count;
        static constexpr long int remaining_nops_count = total_cycles - fixed_total_cycles - rising_falling_nops_count - falling_rising_nops_count;

        static constexpr long int low_time = (rising_falling_nops_count + fixed_low_cycles) * 1'000'000 / frequency_khz;

        static_assert(low_time <= 550, "The clock speed is too low. Did you set F_CPU correctly?");
    };

    template <size_t cycles>
    inline void __attribute__((always_inline)) wait() {
        for(size_t i = 0; i < cycles; i++) {
            asm volatile("nop\n\t");
        }
    }

    template <typename Pin, auto led_count>
    void WS2812B<Pin, led_count>::show(const std::array<GRBColor, led_count>& colors) {
        Pin::template dir<Hal::Output>();

        std::byte ctr;
        std::byte high_mask;
        std::byte low_mask;

        volatile std::byte* port_address = static_cast<volatile std::byte*>(&Port::get()) - 0x20;

        high_mask = Port::ddr();
        low_mask = Port::get() & ~high_mask;
        high_mask |= Port::get();

        std::byte current_byte;
        for(const auto& color: colors){
            auto color_bytes = reinterpret_cast<const std::byte *>(&color);
            constexpr auto byte_count = 3;
            for(size_t i = 0; i < byte_count; i++) {
                current_byte = *color_bytes++;
                asm volatile(
                "       ldi   %0,8  \n\t"
                "loop:              \n\t"
                "       out   %2,%3 \n\t"
                : "=&d" (ctr)
                : "r"(current_byte), "I"(port_address), "r" (high_mask), "r" (low_mask));
                wait<rising_falling_nops_count>();
                asm volatile(
                "       sbrs  %1,7  \n\t"
                "       out   %2,%4 \n\t"
                "       lsl   %1    \n\t"
                : "=&d" (ctr)
                : "r"(current_byte), "I"(port_address), "r" (high_mask), "r" (low_mask));
                wait<falling_rising_nops_count>();
                asm volatile(
                "       out   %2,%4 \n\t"
                : "=&d" (ctr)
                : "r"(current_byte), "I"(port_address), "r" (high_mask),
                "r"(low_mask));
                wait<remaining_nops_count>();
                asm volatile(
                "       dec   %0    \n\t"
                "       brne  loop  \n\t"
                : "=&d" (ctr)
                : "r"(current_byte), "I"(port_address), "r" (high_mask), "r" (low_mask));
            }
        }
    }
}