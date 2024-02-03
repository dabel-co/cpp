#include "FragTrap.hpp"

int main()
{
    FragTrap a("David");
    FragTrap b("Goliat");
    
    b.beRepaired(30);
    b.attack("David"); 
    a.highFivesGuys();
    return (0);
}