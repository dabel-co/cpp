#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <string>
# include "Brain.hpp"


class Dog:public Animal
{
	public:
		// Constructors
		Dog();
		Dog(const Dog &copy);
		
		// Destructor
		virtual ~Dog();
		
		// Operators
		Dog & operator=(const Dog &assign);
		virtual void	makeSound() const;
		Brain*	get_brain();
	private:
		Brain* brain;
};

#endif