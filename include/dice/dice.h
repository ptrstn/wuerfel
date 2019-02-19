#pragma  once
#include <cstdlib>
#include <chrono>

#include "avr/util.h"

#include "leds/ws2812b.h"
#include "leds/neomatrix.h"

namespace BMCPP{
    template<auto dice_sides=6>
    struct Dice{
        auto static roll(){
            return std::rand() % dice_sides + 1;
        }
    };

    template<typename Pin, auto dice_sides=6, auto brightness=5>
    class LedDice{
        static_assert(dice_sides < 7, "Dice side count has to be lower than 7");

        constexpr static size_t led_row_count = 8;
        constexpr static size_t led_column_count = 8;
        constexpr static size_t led_count = led_row_count * led_column_count;

        using leds = WS2812B<Pin, led_count>;
        using neomatrix = NeoMatrix<brightness>;
        using dice = Dice<dice_sides>;

    public:
        void static roll() {
            using namespace std::literals;

            auto fast_roll_amount = Dice<100>::roll();
            for(auto i = 0; i < fast_roll_amount; i++){
                delay(50_ms);
                leds::show(neomatrix::Pattern::numbers[dice::roll() - 1]);
            }

            auto slow_roll_amount = Dice<4>::roll();
            for(auto i = 0; i < slow_roll_amount; i++){
                delay(500_ms);
                leds::show(neomatrix::Pattern::numbers[dice::roll() - 1]);
            }

        }
    };
}
