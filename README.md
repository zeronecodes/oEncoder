# Optical Encoder Project

## Overview

This project is an optical encoder designed to encode 62 numerical characters (0-9, a-z, A-Z) from a keyboard over a serial channel and output these encoded characters to 6 LEDs. The project is written in embedded C and designed to run on an ATMEGA328 MCU interfaced with an FT232RL USB to Serial adapter.

## Project Structure

### Include Files
- **`delay.h`**: Defines functions for millisecond and microsecond delays.
- **`led.h`**: Contains function prototypes for LED control and initialization.
- **`reg_map.h`**: Defines the registers in the ATMega328/P microcontroller.
- **`usart.h`**: Defines functions for serial communication with a terminal emulator.
- **`util.h`**: Contains utility function prototypes, such as division modulus.

### Source Files
- **`led.c`**: Implements the LED control and initialization functions.
- **`interrupt.c`**: Contains code to handle interrupts.
- **`util.c`**: Implements utility functions.
- **`usart.c`**: Defines functions used for communication with the terminal emulator.
- **`oencoder.c`**: The main file implementing the optical encoder logic.
- **`Makefile`**: Contains the build instructions for the project.

## Detailed Functionality

### LED Control and Initialization
- **`init_led()`**: Initializes the LEDs. This function must be called before using the LED ON and OFF functions.
- **LED ON/OFF Functions**: Implemented in `led.c` and the prototypes are defined in `led.h`.

### Delays
- **`delay_ms()`**: Introduces a delay in milliseconds.
- **`delay_us()`**: Introduces a delay in microseconds.

### Register Definitions
- **`reg_map.h`**: Contains definitions for the registers in the ATMega328/P microcontroller.

### Interrupt Handling
- **`interrupt.c`**: Contains the code required to handle interrupts appropriately.

### Utility Functions
- **`util.c`**: Implements various utility functions such as division modulus operations.
- **`util.h`**: Contains the corresponding function prototypes.

### Serial Communication
- **`usart.c` & `usart.h`**: Define functions for communicating with a terminal emulator running on the development PC.
- **`sscanc()`**: Reads a character from the terminal emulator.
- **`init_usart()`**: Initializes the serial communication channel.
- **Error Handling**: `sscanc()` may return errors which should be handled accordingly in the implementation.

### Configuration for Serial Terminal
Use the following configuration for Tera Term or Screen:
- Speed: 9600
- Data: 8-bit
- Parity: None
- Stop bits: 1 bit
- Flow control: None

## Building and Running the Project

### Prerequisites
- ATMEGA328 MCU
- FT232RL USB to Serial adapter
- 6 LEDs
- Development PC with terminal emulator (e.g., Tera Term, Screen)

### Steps
1. **Initialize the LEDs** by calling `init_led()`.
2. **Set up the serial communication** by calling `init_usart()` with the correct configuration.
3. **Compile the project** using the provided `Makefile`.
4. **Upload the compiled code** to the ATMEGA328 MCU.
5. **Run the terminal emulator** with the specified configuration to start encoding characters and observe the LED outputs.