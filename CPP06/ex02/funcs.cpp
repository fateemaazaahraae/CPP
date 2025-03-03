# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base*   generate(void)
{
    int i;

    srand(time(NULL));
    i = rand();
    if (i % 5 == 0)
        return (new A());
    else if (i % 3 == 0)
        return (new B());
    else
        return (new C());    
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "The actual type of the pointer is A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "The actual type of the pointer is B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "The actual type of the pointer is C" << std::endl;
    else
        std::cout << "Unknown type of the pointer" << std::endl;
}

void    identify(Base& p)
{
    //! A
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "The actual type of the reference is A" << std::endl;
        return;
    }
    catch (const std::exception& e)
    {
        // std::cout << e.what() << std::endl;
    }
    //! B
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "The actual type of the reference is B" << std::endl;
        return;
    }
    catch (const std::exception& e)
    {
        // std::cout << e.what() << std::endl;
    }
    //! C
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "The actual type of the reference is C" << std::endl;
        return;
    }
    catch (const std::exception& e)
    {
        // std::cout << e.what() << std::endl;
    }
    std::cout << "Unknown type of the reference" << std::endl;
}
