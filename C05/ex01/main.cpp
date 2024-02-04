#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
    try 
    {
        Bureaucrat pedro("Pedro de la cruz", 20);
        Form formulario("boring_form", 10, 20);
        pedro.signForm(formulario);
    }
    catch(Bureaucrat::GradeTooHighException & e)
    {
        std::cout << e.what() << std::endl;
    }
     catch(Bureaucrat::GradeTooLowException & e)
    {
        std::cout << e.what() << std::endl;
    }
     catch(Form::GradeTooLowException & e)
    {
        std::cout << e.what() << std::endl;
    }
    

}