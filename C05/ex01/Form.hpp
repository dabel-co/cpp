#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
class Bureaucrat;
class Form
{
	public:
		// Constructors
		Form(std::string name, const int signed_grade, const int execute_grande);
		Form(const Form &copy);
		
		// Destructor
		~Form();
		
		// Operators
		Form & operator=(const Form &assign);

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
		bool get_signed_status() const;
		int	required_sign_grade() const;
		int	required_execute_grade() const;
		void	beSigned(Bureaucrat &x);
		
	private:
		const std::string name;
		bool	is_signed;
		const int signed_grade;
		const int execute_grade;
		
};
std::ostream & operator<<(std::ostream &stream, const Form &object);
#endif