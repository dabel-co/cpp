#include "Weapon.hpp"

class HumanB {
    public :
        HumanB(std::string name);
        ~HumanB(void);
        HumanB  attack(void);
        HumanB setWeapon(Weapon &weapon);

    private :
        std::string name;
        Weapon &weapon;  
};
