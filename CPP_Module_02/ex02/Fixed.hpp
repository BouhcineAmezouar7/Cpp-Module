#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int fp;
    static const int fractional = 8;

public:
    Fixed();                              // default constructor
    Fixed(const Fixed &other);            // copy constructor
    Fixed(const int intNum);              // int constructor
    Fixed(const float floatNum);          // float constructor
    Fixed &operator=(const Fixed &other); // copy assignment operator
    ~Fixed();                             // destructor
    int getRawBits(void) const;           // getter
    void setRawBits(int const raw);       // setter
    float toFloat(void) const;            // converts the fixed-point value to a floating-point value
    int toInt(void) const;                // converts the fixed-point value to an integer value
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;
    Fixed &operator++();       // Prefix increment
    Fixed operator++(int);    // Postfix increment
    Fixed &operator--();       // Prefix decrement
    Fixed operator--(int);    // Postfix decrement
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed); // insertion operator overload