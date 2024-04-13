#include "Span.hpp"

int main()
{
    try {
        {   //subject test
            Span sp = Span(5);
            sp.addNumber(6);
            sp.addNumber(2);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(110);
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        {   // Test with 10000 random numbers
            Span sp = Span(10000);
            int array[10000];
            srand(time(NULL));
            for (int i = 0; i < 10000; i++)
                array[i] = rand();
            sp.addNumbers(array, array + 10000);
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}