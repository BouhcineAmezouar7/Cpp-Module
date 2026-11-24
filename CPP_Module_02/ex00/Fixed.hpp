#pragma once

#include <iostream>

class Fixed
{
private:
    int fp;
    static const int fractional = 8;

public:
    Fixed(); // default constructor
    Fixed(const Fixed &other); // copy constructor
    Fixed &operator=(const Fixed &other); // copy assignment operator
    ~Fixed(); // destructor
    int getRawBits(void) const;
    void setRawBits(int const raw);
};