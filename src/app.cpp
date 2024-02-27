#include "pico/stdlib.h"

#include "I2c.hpp"
#include "Ht16k33.hpp"
#include "Adc.hpp"
#include "Time.hpp"

int main(){
    // Create an I2C object
    I2c i2c;

    // Initialize the display
    Ht16k33 display(i2c);

    // Initialize the adc input on pin 28
    Adc adc(28);

    // Display the colon on the display
    display.display_colon();

    Time previous_time(0);

    while(true){
        // Read a time offset using the adc
        const uint64_t offset = adc.read_stable(64'000) * 3600 * 24 / 4096;

        // Calculate the current time
        Time current_time(time_us_64() / 1'000'000 + offset);

        // Display the time
        current_time.display(display);
    }
    return 0;
}
