#include "Base.hpp"

Base* generate(void)
{
    srand(time(0));
    int v1 = rand() % 3;
    if (v1 == 0)
        return (new A);
    else if (v1 == 1)
        return (new B);
    else
        return (new C);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Object type = A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Object type = B" << std::endl;
    else
        std::cout << "Object type = C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "Object type = A" << std::endl;
        (void)a;
    }
    catch(const std::exception& e) {}
    try 
    {
        B& b = dynamic_cast<B&>(p);
        std::cout << "Object type = B" << std::endl;
        (void)b;
    } 
    catch( const std::exception& e ) {}
    try //value of type 'C' is not contextually convertible to 'bool'
    {
        C& c = dynamic_cast<C&>(p);
        std::cout << "Object type = C" << std::endl;
        (void)c;
    } 
    catch( const std::exception& e ) {}
}

int main()
{
    Base *x = generate();  
    identify(x);
    identify(*x);
    delete x;
    return (0);
}