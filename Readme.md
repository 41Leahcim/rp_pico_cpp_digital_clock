# Digital Clock
This application uses a Raspberry Pico, potmeter (or other analog input), and HT16K33 7-segment display to display the current time.
The application is written in C++ and uses the pico_sdk as it's only dependency.
You will also need the compiler for the Raspberry Pico.
You can read how you can install this [here](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf).
I haven't measured yet, how long it could run on batteries or a powerbank.

## Wiring
The Analog input must be connected to gpio 28, ADC_VREF, and ADC_GND. The HT16K33 must be connected to the default I2C pins (SDA to GPIO4, SCL to GPIO5), 3V3, and a GND of the Raspberry Pico.

## Energy usage
Can run for more than 1 day on a small powerbank.