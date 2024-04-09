#ifndef ITER_HPP
#define ITER_HPP

# include <iostream>

template<typename X>
void iter(X *array, int size, void(*f)(X const &))
{
    for (int i = 0; i < size; i++)
        f(array[i]);
}
#endif