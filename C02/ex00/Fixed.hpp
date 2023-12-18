#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed{
public : 
    Fixed();
    virtual ~Fixed();
    Fixed(const Fixed &fixed); //construstor de copia, con el delete prohibimos que se pueda copiar, esto es la implementacion btw
    Fixed & operator=(const Fixed &assign);  // si a = b , entonces b es assign, 0 es lo mismo que delete practicamente
    int getRawBits(void) const;
    void setRawBits(int const raw);

private :
    int                 fixedPointValue;
    static const int    fractionalBits = 8;
};

#endif 