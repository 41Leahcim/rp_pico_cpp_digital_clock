#include "Time.hpp"

#include "Ht16k33.hpp"

// Initialize the time
Time::Time(uint64_t secs) : hours(secs / 3600 % 24), minutes(secs / 60 % 60), seconds(secs % 60){}

void Time::display(Ht16k33& display) const{
    // Display the number of hours on the display
    display.display_digit(0, hours.count()  / 10 % 10);
    display.display_digit(1, hours.count() % 10);

    // Display the number of minutes on the display.
    // Include a dot on the last display to make it easy to find the lower-right
    display.display_digit(2, minutes.count() / 10 % 10);
    display.display_digit_with_dot(3, minutes.count() % 10);
}
