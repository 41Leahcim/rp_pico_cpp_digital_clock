#include <iostream>
#include "pico/stdlib.h"

#include "I2c.hpp"
#include "Ht16k33.hpp"
#include "Adc.hpp"
#include "Time.hpp"

int main(){
    // Create an I2C object
    I2c i2c;
    stdio_init_all();

    // Initialize the display
    Ht16k33 display(i2c);

    // Initialize the adc input on pin 28
    Adc adc(28);

    // Display the colon on the display
    display.display_colon();
    display.set_brightness(8);

    while(true){
        const uint64_t start = time_us_64();
        // Read a time offset using the adc
        const uint64_t offset = adc.read_stable(1024, 728) * 3600 * 24 / 4096;

        // Calculate the current time
        Time current_time(start / 1'000'000 + offset);

        // Display the time
        current_time.display(display);
        
        const uint64_t duration = time_us_64() - start;
        if(duration < 9000){
            sleep_us(9000 - duration);
        }
    }
    return 0;
}
