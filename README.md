# myavrlib

**myavrlib** is a static C library for the ATmega328P (Arduino Uno, 16 MHz) built during the 42 Embedded Piscine. It wraps the MCU's peripherals behind a clean API so exercises can focus on logic rather than register manipulation.

## ⚙️ Features

- Bit manipulation macros (`BITSET`, `BITCLR`, `BITTOG`, `BITCHECK`)
- GPIO control for the piscine board's LEDs (D1–D4, D5 RGB) and buttons (SW1, SW2)
- UART communication at 115200 baud with print helpers and debug mode
- Timer configuration for Timer 0 (8-bit), Timer 1 (16-bit), Timer 2 (8-bit): CTC, Fast PWM, prescalers, output compare
- External interrupt management (INT0, INT1) with edge selection (`RISING`, `FALLING`, `CHANGE`, `LOW`)
- ISR vector macros for all 26 ATmega328P interrupt sources
- ADC with configurable voltage reference, channel, and resolution (8 or 10-bit)
- I2C master driver (TWI) at 100 kHz
- Internal EEPROM read/write (1 KB, addresses `0x000`–`0x3FF`)
- SPI master driver

## 🧠 Learning Objectives

- Direct register manipulation on a bare-metal MCU
- Timer modes: CTC, Fast PWM, prescaling, output compare units
- Hardware communication protocols: UART, I2C, SPI
- Interrupt-driven programming and ISR vector table
- ADC conversion pipeline and analog reference selection
- Persistent storage with EEPROM

## 🔧 Build

```bash
make        # produces myavrlib.a
make debug  # enables dbg_* UART functions via -DDEBUG
```

Copy `Makefile.template` into your project, set `LIBPATH` to point to this repo, then:

```bash
make       # compile + flash to /dev/ttyUSB0
make show  # compile + flash + open serial monitor
```

avr-gcc 5.4.0, target: avr, MCU: atmega328p, F_CPU: 16000000UL
