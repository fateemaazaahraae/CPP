# include "Intern.hpp"

int main()
{
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm(" request", "Bender");

        if (rrf)
        {
            std::cout << "The form has been created succesfully" << std::endl;
            delete rrf;
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}