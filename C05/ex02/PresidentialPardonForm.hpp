#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "FormA.hpp"

class PresidentialPardonForm: public FormA
{
	public:
		// Constructors
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		
		// Destructor
		~PresidentialPardonForm();
		
		// Operators
		PresidentialPardonForm & operator=(const PresidentialPardonForm &assign);
		virtual void	execute(Bureaucrat & executor) const;
	private:
		
		
};

#endif