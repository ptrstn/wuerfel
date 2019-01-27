# Ports

ATmega328p has 4 Ports:

- Port_A
- Port_B
- Port_C
- Port_D

Software wise, each port has 3 (8 Bit) Registers:

- DDRx: Data Direction Register, Input (0) or Output (1)
- PORTx:  Data Register, or Data Output Register. This will appear on the output pins. Only if they are configured as outputs.
 If we want to read the data from a specific pin then we use the input port register
- PINx: Input Port Register.

mnemonic:
- p**O**rt -> Output
- p**I**n -> Input


AVR Instruction Set Manual:
http://ww1.microchip.com/downloads/en/devicedoc/atmel-0856-avr-instruction-set-manual.pdf