#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <iostream>
# include <vector>
# include <stack>
# include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() 
        {
            std::cout << "\e[0;33mDefault Constructor called of MutantStack\e[0m" << std::endl;
        }
        MutantStack(const MutantStack &copy) : std::stack<T>(copy)
        {
            std::cout << "\e[0;33mCopy Constructor called of MutantStack\e[0m" << std::endl;
        }
        MutantStack &operator=(const MutantStack &copy)
        {
            if (this == &copy)
                return *this;
            std::stack<T>::operator=(copy);
            std::cout << "\e[0;33mAssignation operator called for MutantStack\e[0m" << std::endl;
            return *this;
        }
        virtual ~MutantStack() {}

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin() { return std::stack<T>::c.begin(); }
        iterator end() { return std::stack<T>::c.end(); }
};
#endif