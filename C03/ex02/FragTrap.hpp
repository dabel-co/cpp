#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class FragTrap:public ClapTrap
{
	public:
		// Constructors
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);
		
		// Destructor
		~FragTrap();
		
		// Operators
		FragTrap & operator=(const FragTrap &assign);
		void highFivesGuys(void);
		
	private:
		
};

#endif