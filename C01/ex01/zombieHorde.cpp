#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name)
{
    int i = 0;
    Zombie *r = (new Zombie[n]);
    while (i < n)
    {
        r[i].givename(name);
        i++;
    }
    return (r);

}