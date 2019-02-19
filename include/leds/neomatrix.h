# pragma once

#include "leds/colors.h"

namespace BMCPP{
    template<auto brightness = 5>
    struct NeoMatrix{
        constexpr static size_t led_count = 64;
        struct Pattern{
            using color = Color<brightness>;
            constexpr static std::array<GRBColor, led_count> clear{};
            constexpr static std::array<GRBColor, led_count> one
                    {
                            {
                                    color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,
                                    color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,
                                    color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,
                                    color::black,  color::black,  color::black,  color::yellow, color::yellow, color::black,  color::black,  color::black,
                                    color::black,  color::black,  color::black,  color::yellow, color::yellow, color::black,  color::black,  color::black,
                                    color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,
                                    color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,
                                    color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,
                            }
                    };
            constexpr static std::array<GRBColor, led_count> two
                    {
                            {
                                    color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,
                                    color::black,  color::pink,   color::pink,   color::black,  color::black,  color::black,  color::black,  color::black,
                                    color::black,  color::pink,   color::pink,   color::black,  color::black,  color::black,  color::black,  color::black,
                                    color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,
                                    color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,
                                    color::black,  color::black,  color::black,  color::black,  color::black,  color::pink,   color::pink,   color::black,
                                    color::black,  color::black,  color::black,  color::black,  color::black,  color::pink,   color::pink,   color::black,
                                    color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,
                            }
                    };
            constexpr static std::array<GRBColor, led_count> three
                    {
                            {
                                    color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,
                                    color::black,  color::orange, color::orange, color::black,  color::black,  color::black,  color::black,  color::black,
                                    color::black,  color::orange, color::orange, color::black,  color::black,  color::black,  color::black,  color::black,
                                    color::black,  color::black,  color::black,  color::orange, color::orange, color::black,  color::black,  color::black,
                                    color::black,  color::black,  color::black,  color::orange, color::orange, color::black,  color::black,  color::black,
                                    color::black,  color::black,  color::black,  color::black,  color::black,  color::orange, color::orange, color::black,
                                    color::black,  color::black,  color::black,  color::black,  color::black,  color::orange, color::orange, color::black,
                                    color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,
                            }
                    };
            constexpr static std::array<GRBColor, led_count> four
                    {
                            {
                                    color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,
                                    color::black,  color::blue,   color::blue,   color::black,  color::black,  color::blue,   color::blue,   color::black,
                                    color::black,  color::blue,   color::blue,   color::black,  color::black,  color::blue,   color::blue,   color::black,
                                    color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,
                                    color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,
                                    color::black,  color::blue,   color::blue,   color::black,  color::black,  color::blue,   color::blue,   color::black,
                                    color::black,  color::blue,   color::blue,   color::black,  color::black,  color::blue,   color::blue,   color::black,
                                    color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,
                            }
                    };

            constexpr static std::array<GRBColor, led_count> five
                    {
                            {
                                    color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,
                                    color::black,  color::red,    color::red,    color::black,  color::black,  color::red,    color::red,    color::black,
                                    color::black,  color::red,    color::red,    color::black,  color::black,  color::red,    color::red,    color::black,
                                    color::black,  color::black,  color::black,  color::red,    color::red,    color::black,  color::black,  color::black,
                                    color::black,  color::black,  color::black,  color::red,    color::red,    color::black,  color::black,  color::black,
                                    color::black,  color::red,    color::red,    color::black,  color::black,  color::red,    color::red,    color::black,
                                    color::black,  color::red,    color::red,    color::black,  color::black,  color::red,    color::red,    color::black,
                                    color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,
                            }
                    };
            constexpr static std::array<GRBColor, led_count> six
                    {
                            {
                                    color::black,  color::green,  color::green,  color::black,  color::black,  color::green,  color::green,  color::black,
                                    color::black,  color::green,  color::green,  color::black,  color::black,  color::green,  color::green,  color::black,
                                    color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,
                                    color::black,  color::green,  color::green,  color::black,  color::black,  color::green,  color::green,  color::black,
                                    color::black,  color::green,  color::green,  color::black,  color::black,  color::green,  color::green,  color::black,
                                    color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,  color::black,
                                    color::black,  color::green,  color::green,  color::black,  color::black,  color::green,  color::green,  color::black,
                                    color::black,  color::green,  color::green,  color::black,  color::black,  color::green,  color::green,  color::black,
                            }
                    };
            constexpr static std::array<std::array<GRBColor, led_count>, 6> numbers = {one, two, three, four, five, six};
        };
    };
}
