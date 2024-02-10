#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap(std::string name) :ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "Constructor called of ScavTrap " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) :ClapTrap(copy)
{
	std::cout << "Copy Constructor called of ScavTrap" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called of ScavTrap " << name << std::endl;
}

// Operators
ScavTrap & ScavTrap::operator=(const ScavTrap &assign)
{
	ClapTrap::operator=(assign);
	return *this;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}

void    ScavTrap::attack(const std::string &target)
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
    std::cout << "ScavTrap " << this->name << " attacks WOOOOO " << target << std::endl;
    victim->takeDamage(this->attack_damage);
}