#include "HumanB.hpp"

HumanB::HumanB(std::string name): weapon(NULL)
{
    this->name = name;
}

HumanB::~HumanB(void)
{}

void HumanB::attack()
{
    std::cout << this->name << " : attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}