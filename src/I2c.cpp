#include "I2c.hpp"

#include "hardware/i2c.h"
#include "pico/stdlib.h"

I2c::I2c(){
    // Initialize the I2C with a bitrate of 100000
    i2c_init(i2c_default, 100'000);

    // Initialize the default I2C pins
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);

    // Set the pull-ups on the default I2C pins
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
}

void I2c::send_byte(const uint8_t address, const uint8_t value) const{
    // Write the byte over I2C
    i2c_write_blocking(i2c_default, address, &value, 1, false);
}

void I2c::send_bytes(const uint8_t address, const uint8_t *bytes, const size_t length) const{
    // Send all bytes over I2C
    i2c_write_blocking(i2c_default, address, bytes, length, false);
}
