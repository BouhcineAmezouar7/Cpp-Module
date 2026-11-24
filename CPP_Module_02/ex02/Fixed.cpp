#include "Fixed.hpp"

Fixed::Fixed()
{
    fp = 0;
}

Fixed::~Fixed() {}

Fixed::Fixed(const int fixed_p)
{
    fp = fixed_p * (1 << fractional);
}

Fixed::Fixed(const float fixed_p)
{
    fp = roundf(fixed_p * (1 << fractional));
}

Fixed::Fixed(const Fixed &other) : fp(other.fp) {}

Fixed &Fixed::operator=(const Fixed &other)
{
    this->fp = other.fp;
    return *this;
}

int Fixed::getRawBits(void) const
{
    return fp;
}

void Fixed::setRawBits(int const raw)
{
    fp = raw;
}

float Fixed::toFloat(void) const
{
    return (float)fp / (1 << fractional);
}

int Fixed::toInt(void) const
{
    return (fp >> fractional);
}

std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
    os << f.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->fp > other.fp;
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->fp < other.fp;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->fp >= other.fp;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->fp <= other.fp;
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->fp == other.fp;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->fp != other.fp;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++() // Prefix increment
{
    this->fp++;
    return *this;
}

Fixed Fixed::operator++(int) // Postfix increment
{
    Fixed temp = *this;
    this->fp++;
    return temp;
}

Fixed &Fixed::operator--() // Prefix decrement
{
    this->fp--;
    return *this;
}

Fixed Fixed::operator--(int) // Postfix decrement
{
    Fixed temp = *this;
    this->fp--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}
