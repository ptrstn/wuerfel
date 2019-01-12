#include <avr/io.h>
#include <util/delay.h>

#include "avr/mega328.h"
#include "avr/util.h"

#include "hal/port.h"

#include <chrono>

using namespace BMCPP::Hal;

using Portb = Port<BMCPP::AVR::B>;
using Portc = Port<BMCPP::AVR::C>;

using LedPin = Pin<Portb, 1>;
using LedPin2 = Pin<Portb, 5>;
using LedPin3 = Pin<Portc, 0>;

using Leds = PinSet<LedPin, LedPin2>;

int main() {
    using namespace std::literals;
    
    Leds::template dir<Output>();

    while(true) {
        BMCPP::delay(500_ms);
        Leds::allOn();
        BMCPP::delay(100_us);
        Leds::allOff();
    }
    
}