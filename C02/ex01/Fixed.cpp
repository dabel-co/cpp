#include "Fixed.hpp"
#include <assert.h>
#include <iostream>

Fixed::Fixed() : fixedPointValue(0)
{
    std::cerr << "Default Constructor called of Fixed" << std::endl; //ceer as que lo manda sin usar pipes para debug
}

Fixed::Fixed(const int value)
{
    assert(value < 8388608);
    assert(value > -8388609);
    this->fixedPointValue = value << fractionalBits;
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

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return (o);
}