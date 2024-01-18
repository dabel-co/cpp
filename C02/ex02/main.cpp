#include <iostream>
#include "Fixed.hpp"
    
int main()
{
    Fixed a(0);
    Fixed r(0);
   // Fixed const b(Fixed(5.05f) / Fixed(2));

    std::cout << "++x routine" << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;

    std::cout << "--x routine" << std::endl;
    std::cout << a << std::endl;
    std::cout << --a << std::endl;
    std::cout << a << std::endl;

    std::cout << "x++ routine" << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << "x-- routine" << std::endl;
    std::cout << a << std::endl;
    std::cout << a-- << std::endl;
    std::cout << a << std::endl;
    


    if (a == r)
        std::cout << "a == r" << std::endl;
    if (a != r)
        std::cout << "a != r" << std::endl;
    if (a < r)
        std::cout << "a < r" << std::endl;
    if (a > r)
        std::cout << "a > r" << std::endl;
    if (a >= r)
        std::cout << "a >= r" << std::endl;
    if (a <= r)
        std::cout << "a <= r" << std::endl;
    
    a = 1;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    a = a + b;
    std::cout << "la suma de a + b es = "<< a << std::endl;
    std::cout << "esto es a = " << a << std::endl;
    std::cout << "esto es b = " << b << std::endl;
    a = a - b;
    std::cout << "la suma de a - b es = "<< a << std::endl;
    a = 5;
    a = a * b;
    std::cout << "la operación a * b es = "<< a << std::endl;
    a = a / b;
    std::cout << "la operación a / b es = "<< a << std::endl;

    
    
    
    
    std::cout << "max is " << Fixed::max(a, b) << std::endl;
    std::cout << "min is " << Fixed::min(a, b) << std::endl;

    return 0;
}

