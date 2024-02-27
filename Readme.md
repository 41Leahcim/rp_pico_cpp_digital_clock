# Digital Clock
This application uses a Raspberry Pico, potmeter (or other analog input), and HT16K33 7-segment display to display the current time.
The application is written in C++ and uses the pico_sdk as it's only dependency.
You will also need the compiler for the Raspberry Pico.
You can read how you can install this [here](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf).
I haven't measured yet, how long it could run on batteries or a powerbank.

## Wiring
The Analog input must be connected to gpio 28. The HT16K33 must be connected to the default I2C pins (SDA to GPIO4, SCL to GPIO5).
Both run on 3.3V so both can be fully powered by the 3.3V output pin of the Raspberry Pico.