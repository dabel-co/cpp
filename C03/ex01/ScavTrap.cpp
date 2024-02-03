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