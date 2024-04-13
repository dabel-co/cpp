#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <iostream>
# include <vector>
template<typename T>
int easyfind(T *haystack, int needle)
{
    typename T::iterator it = std::find(haystack->begin(), haystack->end(), needle);
    if (it == haystack->end() && *it != needle)
        throw std::exception();
    std::cout << "Found needle : " << needle << std::endl;
    return (0);
}
#endif