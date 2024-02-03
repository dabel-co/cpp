#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap(std::string name) :ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "Constructor called of FragTrap " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) :ClapTrap(copy)
{
	std::cout << "Copy Constructor called of FragTrap" << std::endl;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "Destructor called of ScavTrap " << name << std::endl;
}

// Operators
FragTrap & FragTrap::operator=(const FragTrap &assign)
{
	ClapTrap::operator=(assign);
	return *this;
}
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " requested a high five" << std::endl;
}

