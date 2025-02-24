# include "Bureaucrat.hpp"
# include "Form.hpp"

int main()
{
    Bureaucrat a("fateemaazaahraae", 90);
    Form form("Job", 100, 50);
    a.signForm(form);
    std::cout << "The After" << std::endl;
    std::cout << a;
    std::cout << form;
    // try
    // {
    //     /* do some stuff with bureaucrats */
    //     Bureaucrat b("amina", 10);
    //     Bureaucrat a(b);
    //     std::cout << b;
    // }
    // catch (std::exception & e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
}