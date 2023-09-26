

#ifndef WEAPON_HPP

# define WEAPON_HPP

# include <iostream>
#include <iostream>

class Weapon {
    public :
        Weapon(std::string type);
        ~Weapon(void);
        const   std::string &getType();
        void    setType(std::string type);

    private :
        std::string type;
};  
#endif