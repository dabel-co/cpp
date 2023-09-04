#include "Zombie.hpp"
int main()
{
    int i = 0;
    Zombie *r = zombieHorde(6, "pedritos");
    while (i < 6)
    {
        r[i].announce();
        i++;
    }
    delete[] r;
    return (0);

}