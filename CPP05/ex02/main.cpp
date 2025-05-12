# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main()
{
    //! ShrubberyCreationForm
    std::cout << "\n\n##### ShrubberyCreationForm #####\n" << std::endl; 
    try 
    {
        Bureaucrat b("BURR", 15);
        Bureaucrat a("A", 1);
        ShrubberyCreationForm bery("BURR");
        std::cout << b << std::endl;
        std::cout << bery << std::endl;
        b.executeForm(bery);
        bery.beSigned(a);
        b.executeForm(bery);
    }
    catch (const std::exception& e)
    {
        std::cout << "------> " << e.what() << std::endl;
    }

    //! RobotomyRequestForm
    std::cout << "\n\n##### RobotomyRequestForm #####\n" << std::endl; 
    try
    {
        Bureaucrat c("C", 10);
        RobotomyRequestForm robot("ROBOT");
        std::cout << c << std::endl;
        std::cout << robot << std::endl;
    srand(time(NULL));
        c.executeForm(robot);
        robot.beSigned(c);
        c.executeForm(robot);
        c.executeForm(robot);
        c.executeForm(robot);
        c.executeForm(robot);
        c.executeForm(robot);
    }
    catch (const std::exception& e)
    {
        std::cout << "------> " << e.what() << std::endl;
    }

    //! PresidentialPardonForm
    std::cout << "\n\n##### PresidentialPardonForm #####\n" << std::endl; 
    try
    {
        Bureaucrat d("D", 2);
        PresidentialPardonForm pre("PRE");
        std::cout << d << std::endl;
        std::cout << pre << std::endl;
        d.executeForm(pre);
        pre.beSigned(d);
        d.executeForm(pre);
    }
    catch (const std::exception& e)
    {
        std::cout << "------> " << e.what() << std::endl;
    }
}