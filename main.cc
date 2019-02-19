#include <cstdint>
#include "avr/mega328.h"
#include "avr/util.h"

#include "leds/ws2812b.h"
#include "leds/colors.h"
#include "leds/neomatrix.h"
#include "dice/dice.h"

using namespace BMCPP::Hal;

using PortB = Port<BMCPP::AVR::B>;
using leds_pin = Pin<PortB, 0>;
using button_pin = Pin<PortB, 1>;

int main() {
    using namespace BMCPP;
    using namespace std::literals;

    button_pin::template dir<Hal::Input>();

    using led_dice = LedDice<leds_pin, 6>;

    while (true) {
        auto button_pressed = button_pin::read();
        if(button_pressed){
            led_dice::roll();
        }
    }
}
