#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <string>
# include "Brain.hpp"

class Cat:public Animal
{
	public:
		// Constructors
		Cat();
		Cat(const Cat &copy);
		
		// Destructor
		virtual ~Cat();
		
		// Operators
		Cat & operator=(const Cat &assign);
		virtual void	makeSound() const;
		Brain* get_brain();

	private:
		Brain* brain;
};

#endif