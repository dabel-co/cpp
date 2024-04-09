#include "iter.hpp"


void    DisplayMember(int const &x)
{
    std::cout << x << std::endl;
}

int main()
{
    int test[] = {0, 1, 2, 3, 4, 5};
    int size = 5;
    ::iter(test, size, DisplayMember);
    return (0);
}