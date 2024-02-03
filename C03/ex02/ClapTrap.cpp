#include "ClapTrap.hpp"

ClapTrap* ClapTrap::claptrap_array[] = {nullptr, nullptr, nullptr};

// Constructors
ClapTrap::ClapTrap(std::string name) :name(name), hit_points(10), energy_points(10), attack_damage(0) 
{
    std::cout << "Constructor called of ClapTrap " << name << std::endl;
    this->addClapTrap();

}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    *this = copy;
    std::cout << "Copy Constructor called of ClapTrap" << std::endl;
}

// Operators
ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
    this->name = rhs.name;
    this->hit_points = rhs.hit_points;
    this->energy_points = rhs.energy_points;
    this->attack_damage = rhs.attack_damage;
    return *this;
}
// Destructor
ClapTrap::~ClapTrap() {
    std::cout << "Destructor called of ClapTrap " << name << std::endl;
}

void    ClapTrap::addClapTrap()
{
    for (int i = 0; i < max_claptrap; i++)
    {
        if(claptrap_array[i])
            continue;
        else
        {
            claptrap_array[i] = this;
            return ;
        }
    }
    std::cout << "ClapTrap array is full" << std::endl;
}

ClapTrap* ClapTrap::findClapTrap(const std::string &name) const
{
    for (int i = 0; i < max_claptrap; i++)
    {
        if (claptrap_array[i] && name != claptrap_array[i]->name)
            continue;
        return (claptrap_array[i]);
    }
    return (nullptr);
}

void    ClapTrap::attack(const std::string &target)
{
    ClapTrap *victim = findClapTrap(target);
    if (!victim)
    {
        std::cout << "target " << target << "not found" <<std::endl;
        return ;
    }
    if (this->energy_points == 0)
    {
        std::cout << this->name << " is out of energy points" << std::endl;
        return ;
    }
    this->energy_points--;
    std::cout << this->name << " attacks " << target << std::endl;
    victim->takeDamage(this->attack_damage);
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    this->hit_points -= amount;
    if (this->hit_points < 0)
        this->hit_points = 0;
    std::cout << this->name << " has taken " << amount << " damage, hit_points remaining " << this->hit_points << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energy_points == 0)
    {
        std::cout << this->name << " is out of energy points" << std::endl;
        return ;
    }
    this->hit_points += amount;
    std::cout << this->name << " has been repaired, now it has " << this->hit_points << " hit points" << std::endl;
}