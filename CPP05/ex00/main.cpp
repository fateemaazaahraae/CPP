# include "Bureaucrat.hpp"

int main()
{
    try
    {
        /* do some stuff with bureaucrats */
        Bureaucrat b("amina", 10);
        Bureaucrat a(b);
        std::cout << b;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}