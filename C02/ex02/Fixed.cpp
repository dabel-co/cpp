#include "Fixed.hpp"
#include <assert.h>
#include <iostream>

Fixed::Fixed() : fixedPointValue(0)
{
    std::cerr << "Default Constructor called of Fixed" << std::endl; //ceer as que lo manda sin usar pipes para debug
}

Fixed::Fixed(const int value)
{
    this->fixedPointValue = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
    this->fixedPointValue = roundf(value * (1 << fractionalBits));
}

Fixed::~Fixed()
{
    std::cerr << "Destructor called of Fixed" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cerr << "Copy Constructor called of Fixed" << std::endl;
    this->fixedPointValue = fixed.fixedPointValue; //como es la misma clase, accedo directamente
}

Fixed & Fixed::operator=(const Fixed &assign)
{
    std::cerr << "Assing operator called" << std::endl;
    this->fixedPointValue = assign.fixedPointValue;
   return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cerr << "getRawBits member function called" << std::endl;
    return(this->fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    std::cerr << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
    float result;

    result = (float)fixedPointValue;
    result = result / (1 << fractionalBits);
    return(result);
}

int Fixed::toInt(void) const
{
    int result;
    result = fixedPointValue >> fractionalBits;
    if (fixedPointValue < 0)
        result = result | 0xFF000000;
    else
        result = result & 0x00FFFFFF;
    return (result);
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return (o);
}

bool Fixed::operator==(const Fixed &rhs) const
{
    return (this->fixedPointValue == rhs.fixedPointValue);
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return (this->fixedPointValue < rhs.fixedPointValue);
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return !(*this==rhs);
}

bool Fixed::operator>(const Fixed &rhs) const
{
    return !(*this<=rhs);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return !(*this<rhs);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return ((*this<rhs) || (*this==rhs));
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
    Fixed aux(rhs);

    aux.fixedPointValue += this->fixedPointValue;
    return (aux);
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
    Fixed aux(rhs);

    aux.fixedPointValue -= this->fixedPointValue;
    return (aux);
}

Fixed Fixed::operator*(const Fixed &rhs) const //test this
{
    Fixed aux(rhs);

    //aux.fixedPointValue *= this->fixedPointValue;
    aux.fixedPointValue = (this->fixedPointValue * rhs.fixedPointValue) >> fractionalBits;
    return (aux);
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
    Fixed aux(rhs);

    aux.fixedPointValue /= this->fixedPointValue;
    return (aux);
}

Fixed & Fixed::operator++(void)
{
    this->fixedPointValue += 1;
    return (*this);
}

Fixed Fixed::operator++(int n)
{
    Fixed aux(*this);

    this->fixedPointValue += n;
    return (aux);
}

Fixed & Fixed::operator--(void)
{
    this->fixedPointValue -= 1;
    return (*this);
}

Fixed Fixed::operator--(int n)
{
    Fixed aux(*this);

    this->fixedPointValue -= n;
    return (aux);
}

const Fixed & Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b )
        return (a);
    else
        return (b);
}

const Fixed & Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    else
        return (b);
}
