#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("David");
    ClapTrap b("Goliat");

    b.beRepaired(30);
    b.attack("David");
    return (0);
}