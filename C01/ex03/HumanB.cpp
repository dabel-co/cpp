#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
}

HumanB::~HumanB(void)
{}

HumanB::attack()
{
    std::cout << this->name << " : attacks with their " << Weapon << std::endl;
}

HumanB::setWeapon(weapon &weapon)
{
    this->weapon = Weapon;
}