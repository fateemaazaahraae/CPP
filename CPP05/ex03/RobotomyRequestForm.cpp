# include "RobotomyRequestForm.hpp"

//! O.C.F
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

//! Member functions
void    RobotomyRequestForm::robotAction() const {
    srand(time(NULL));
    if (rand() % 2 == 0)
        std::cout << this->_target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "The robotomy failed !!" << std::endl;
}

void    RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    if (getSigned() && executor.getGrade() <= getGradeToExec())
        robotAction();
    else if (!getSigned())
        throw GradeSignException();
    else
        throw GradeTooLowException();
}

AForm*  RobotomyRequestForm::createForm(std::string target) { return new RobotomyRequestForm(target); }