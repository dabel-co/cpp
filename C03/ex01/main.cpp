#include "ScavTrap.hpp"

int main()
{
    ScavTrap a("David");
    ScavTrap b("Goliat");
    
    b.beRepaired(30);
    b.attack("David"); 
    a.guardGate();
    return (0);
}