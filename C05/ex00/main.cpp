#include "Bureaucrat.hpp"

int main()
{
    try 
    {
        Bureaucrat pedro("Pedro de la cruz", 30);
        //Bureaucrat charo("Charo", 160);
        //Bureaucrat ramon("Ramon", 0);
        std::cout << pedro << std::endl;
        //pedro+=150;
    }
    catch(Bureaucrat::GradeTooHighException & e)
    {
        std::cout << e.what() << std::endl;
    }
     catch(Bureaucrat::GradeTooLowException & e)
    {
        std::cout << e.what() << std::endl;
    }
    

}