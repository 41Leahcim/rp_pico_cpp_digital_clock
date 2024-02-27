#pragma once

#include <cinttypes>
#include <cstddef>

class I2c{
public:
    /// @brief Initialize the I2C
    I2c();

    /// @brief Sends a byte over I2C
    /// @param address The address of the device to send data to
    /// @param value The value to send
    void send_byte(const uint8_t address, const uint8_t value) const;

    /// @brief Sends multiple bytes over I2C
    /// @param address The address of the device to send data to
    /// @param bytes The values to send
    /// @param length The number of bytes to send
    void send_bytes(const uint8_t address, const uint8_t *bytes, const size_t length) const;
};
