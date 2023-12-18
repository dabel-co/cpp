#include <iostream>
#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed b( a ); //Fixed::Fixed(const Fixed &fixed)
    Fixed c;

    c = b; //Fixed & Fixed::operator=(const Fixed &assign)
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return (0);
}