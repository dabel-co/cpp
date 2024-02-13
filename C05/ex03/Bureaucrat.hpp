#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
class FormA;
class Bureaucrat
{
	public:
		// Constructors
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		
		// Destructor
		~Bureaucrat();
		
		// Operators
		Bureaucrat & operator=(const Bureaucrat &assign);
		void operator+=(int i);
		void operator-=(int i);
		
		// Exceptions
		class GradeTooHighException : public std::exception {
			public : 
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				virtual const char* what() const throw();
		};
		std::string get_name() const;
		int	get_grade() const;
		void	signForm(FormA & x);
		void	executeForm(FormA const & form);
	private:
		std::string name;
		int grade;
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Bureaucrat &object);

#endif