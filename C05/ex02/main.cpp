#include "Bureaucrat.hpp"
#include "FormA.hpp"
#include "ShrubberyCreationForm.hpp"
int main()
{
    try 
    {
        Bureaucrat pedro("Pedro de la cruz", 150);
        ShrubberyCreationForm formulario("boring_form");
        pedro.signForm(formulario);
        pedro.executeForm(formulario);
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }


}