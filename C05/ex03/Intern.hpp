#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>

class FormA;
class Intern
{
	public:
		// Constructors
		Intern();
		Intern(const Intern &copy);
		
		// Destructor
		~Intern();
		
		// Operators
		Intern & operator=(const Intern &assign);
		
		FormA* makeForm(std::string name, std::string target);
	private:
		
};

#endif