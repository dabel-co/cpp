#ifndef FIXED_HPP
# define FIXED_HPP
#include <ostream>
#include <cmath>

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
    bool operator==(const Fixed &rhs)   const;
    bool operator!=(const Fixed &rhs)   const;
    bool operator<(const Fixed &rhs)    const;
    bool operator<=(const Fixed &rhs)   const;
    bool operator>(const Fixed &rhs)    const;
    bool operator>=(const Fixed &rhs)   const;
    Fixed operator+(const Fixed &rhs)   const;
    Fixed operator-(const Fixed &rhs)   const;
    Fixed operator*(const Fixed &rhs)   const;
    Fixed operator/(const Fixed &rhs)   const;
    Fixed &operator++(void); //++i
    Fixed operator++(int n); //i++
    Fixed &operator--(void); //--i
    Fixed operator--(int n); //i--

    static const Fixed &min(const Fixed &a, const Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);


private :
    int                 fixedPointValue;
    static const int    fractionalBits = 8;
};
    std::ostream & operator<<(std::ostream & o, Fixed const & rhs); //ampliando ostream , rhs = right hand side

#endif 