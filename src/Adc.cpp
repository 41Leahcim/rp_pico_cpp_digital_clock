#include "Adc.hpp"
#include "hardware/adc.h"

Adc::Adc(uint8_t gpio) : pin(gpio), input(gpio - 26) {
    // Initialize the ADC, in case it hasn't been initialized yet
    adc_init();

    // Initialize the requested pin for ADC
    adc_gpio_init(gpio);
}

uint16_t Adc::read() const{
    // Select the adc input channel
    adc_select_input(input);

    // Read the current ADC value
    return adc_read();
}

uint64_t Adc::read_stable(const uint32_t measurements) const{
    // Select the adc input channel
    adc_select_input(input);

    // Perform the requested number of measurements
    uint64_t total = 0;
    for(uint32_t i = 0;i < measurements;i++){
        total += adc_read();
    }

    // Return the average measurement value
    return total / measurements;
}
