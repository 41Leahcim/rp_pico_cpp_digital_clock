#pragma once

#include <cstdint>

class Adc{
private:
    uint8_t pin, input;
public:
    /// @brief Initializes the adc for a pin
    /// @param pin The pin to initialize the adc for
    Adc(uint8_t pin);

    /// @brief Reads the value on the adc pin
    /// @return the current adc value
    uint16_t read() const;

    /// @brief Performs multiple measurements to calculate a more stable value
    /// @param measurements the number of measurements to take
    /// @param clock_divider slows down the adc, minimum is 96
    /// @return the average value measured
    uint64_t read_stable(const uint32_t measurements, const float clock_divider) const;
};
