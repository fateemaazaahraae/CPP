# include "Intern.hpp"

//! O.C.F
Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other) { (void)other; }

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

AForm*  Intern::makeForm(std::string formName, std::string target)
{
    std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    try
    {
        int i;
        for (i = 0; i < 3; i++)
            if (formName == forms[i])
                break;
        switch (i)
        {
            case 0:
                std::cout << "The Intern create " << formName << std::endl;
                return new ShrubberyCreationForm(target);
            case 1:
                std::cout << "The Intern create " << formName << std::endl;
                return new RobotomyRequestForm(target);
            case 2:
                std::cout << "The Intern create " << formName << std::endl;
                return new PresidentialPardonForm(target);
            default:
                throw ErrMessage();
        }
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << formName << std::endl;
    }
    return NULL;
}

//! Exceptions
const char* Intern::ErrMessage::what() const throw() {
    return "Intern Can't create the ";
}