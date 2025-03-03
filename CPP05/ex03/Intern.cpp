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
    AForm* (*Forms[])(std::string) = { 
        &ShrubberyCreationForm::createForm, 
        &RobotomyRequestForm::createForm, 
        &PresidentialPardonForm::createForm 
    };
    std::string arr[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    for (int i = 0; i < 3; i++)
        if (formName == arr[i])
        {
            std::cout << "The Intern create " << formName << std::endl;
            return Forms[i](target);
        }
    throw ErrMessage();
    return NULL;
}

//! Exceptions
const char* Intern::ErrMessage::what() const throw() {
    return "Intern Can't create the Form";
}