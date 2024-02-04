#ifndef BRAIN_HPP
# define BRAIN_HPP


# include <string>

class Brain
{
	public:
		// Constructors
		Brain();
		Brain(const Brain &copy);
		
		// Destructor
		~Brain();
		
		// Operators
		Brain & operator=(const Brain &assign);
		void	set_first_idea(std::string x);
		std::string	get_first_idea();

		
	protected :
		std::string ideas[100];
		
};

#endif