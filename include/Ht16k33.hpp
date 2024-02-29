#pragma once

#include <cstdint>

class I2c;

/// @brief A class for the Ht16k33 7-segment display
class Ht16k33{
private:
    const I2c& i2c;
public:
    /// @brief Initializes the Ht16k33 7-segment display
    /// @param connection The I2C connection for the display, this reference will used later!
    Ht16k33(const I2c& connection);

    /// @brief Displays a digit on the display
    /// @param index The index of the 7-segment displays (0 left - 3 right)
    /// @param digit The digit to display
    void display_digit(const uint8_t index, const uint8_t digit) const;

    /// @brief Displays a digit with a dot
    /// @param index The index of the 7-segment displays (0 left, - 3 right)
    /// @param digit The digit ot display
    void display_digit_with_dot(const uint8_t index, const uint8_t digit) const;

    /// @brief Displays the colon
    void display_colon() const;

    /// @brief Changes the brightness of the display
    /// @param value The brightness value (0 - 15 inclusive)
    void set_brightness(uint8_t value) const;
};

