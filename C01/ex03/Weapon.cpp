#include "Weapon.hpp"

Weapon::Weapon(std:::string type)
{
    this->type = type;
}

Weapon::~Weapon()
{}

const std::string &GetType()
{
    return (this->type);
}

void    setType(std::string type)
{
    this->type = type;
}