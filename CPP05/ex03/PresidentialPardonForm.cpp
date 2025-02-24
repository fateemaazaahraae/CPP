# include "PresidentialPardonForm.hpp"

//! O.C.F
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

//! Member functions
void    PresidentialPardonForm::pardonAction() const {
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

void    PresidentialPardonForm::execute(Bureaucrat const& executor) const {
    if (getSigned() && executor.getGrade() <= getGradeToExec())
        pardonAction();
    else if (!getSigned())
        throw GradeSignException();
    else
        throw GradeTooLowException();
}