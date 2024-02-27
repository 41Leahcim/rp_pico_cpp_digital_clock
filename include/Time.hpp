#pragma once

#include <cstdint>
#include <chrono>

namespace chrono = std::chrono;

class Ht16k33;

class Time{
private:
    chrono::hours hours;
    chrono::minutes minutes;
    chrono::seconds seconds;
public:
    /// @brief Creates a new time instance
    /// @param seconds The number of values to split into hours, minutes, and seconds
    Time(uint64_t seconds);

    /// @brief Displays the current time on a Ht16k33 display
    /// @param display The display to display the time on
    void display(Ht16k33& display) const;
};
