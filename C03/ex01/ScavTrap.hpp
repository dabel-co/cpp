#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class ScavTrap:public ClapTrap
{
	public:
		// Constructors
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);
		
		// Destructor
		~ScavTrap();
		
		// Operators
		ScavTrap & operator=(const ScavTrap &assign);
		 void guardGate();
		 void    attack(const std::string &target);
		
	private:
		
};

#endif