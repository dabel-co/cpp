#ifndef FIXED_HPP
# define FIXED_HPP
#include <ostream>

class Fixed{
public : 
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    virtual ~Fixed();
    Fixed(const Fixed &fixed); //construstor de copia, con el delete prohibimos que se pueda copiar, esto es la implementacion btw
    Fixed & operator=(const Fixed &assign);  // si a = b , entonces b es assign, 0 es lo mismo que delete practicamente
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;


private :
    int                 fixedPointValue;
    static const int    fractionalBits = 8;
};
    std::ostream & operator<<(std::ostream & o, Fixed const & rhs); //ampliando ostream , rhs = right hand side

#endif 