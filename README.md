# Wuerfel

An electronic dice project for the ATmega328P in C++ 

## Requirements

For Arch Linux install following packages:

```bash
sudo pacman -S gcc cmake avr-gcc avr-binutils avr-gdb avr-libc avrdude simavr arduino-avr-core
```

## Compile instructions

```bash
cmake .
```

## Transfer firmware

```bash
cmake .
make upload
```