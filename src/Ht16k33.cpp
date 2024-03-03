#include "Ht16k33.hpp"

#include "I2c.hpp"

const uint8_t address = 0x70;

static const uint8_t charmap[] = {
  0x3F,   //  0
  0x06,   //  1
  0x5B,   //  2
  0x4F,   //  3
  0x66,   //  4
  0x6D,   //  5
  0x7D,   //  6
  0x07,   //  7
  0x7F,   //  8
  0x6F,   //  9
  0x77,   //  A
  0x7C,   //  B
  0x39,   //  C
  0x5E,   //  D
  0x79,   //  E
  0x71,   //  F
  0x00,   //  space
  0x40,   //  minus
  0x61,   //  TOP_C
  0x63,   //  degree °
};

Ht16k33::Ht16k33(const I2c& connection): i2c(connection){
    uint8_t value;
    // Turn the display on
    connection.send_byte(address, 0x21);
    connection.send_byte(address, 0x81);
}

void Ht16k33::display_digit(const uint8_t index, const uint8_t digit) const{
    // A digit is always between 0 and 15 (inclusive) and there are only 4 displays
    if(digit < 16 && index < 4){
        // Calculate the index of the selected display and take the character for the digit
        const uint8_t buffer[2] = {
            (index < 2? index : 1 + index) * 2,
            charmap[digit]
        };
        
        // Display the digit on the display
        i2c.send_bytes(address, buffer, 2);
    }
}

void Ht16k33::display_digit_with_dot(const uint8_t index, const uint8_t digit) const{
    // A digit is always between 0 and 15 (inclusive) and there are only 4 displays
    if(digit < 16 && index < 4){
        // Calculate the index of the selected display and take the character for the digit.
        // Also setting the bit for the dot
        const uint8_t buffer[2] = {
            (index < 2? index : 1 + index) * 2,
            charmap[digit] | 0x80
        };

        // Display the digit and dot on the display
        i2c.send_bytes(address, buffer, 2);
    }
}

void Ht16k33::display_colon() const{
    // Display the ':'
    const uint8_t buffer[2] = {4, 255};
    i2c.send_bytes(address, buffer, 2);
}

void Ht16k33::set_brightness(uint8_t value) const{
    // Make sure the value is less than 15
    value &= 15;

    // Set the brightness
    i2c.send_byte(address,0xe0 | value);
}
