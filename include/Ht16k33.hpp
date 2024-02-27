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
    void display_digit_with_dot(const uint8_t index, const uint8_t digit) const;
    void display_colon() const;
};

