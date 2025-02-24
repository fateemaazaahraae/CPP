# include "Bureaucrat.hpp"
# include "AForm.hpp"

//! O.C.F
Bureaucrat::Bureaucrat() : name("tiima"), grade(150) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const std::string Name, int Grade) : name(Name), grade(Grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other)
        grade = other.grade;
    return *this;
}

//! Getters
std::string const&  Bureaucrat::getName() const { return name; }

int Bureaucrat::getGrade() const { return grade; }

//! The exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too HIGH";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too LOW";
}

//! Member functions
void    Bureaucrat::increment() {
    grade--;
    if (grade < 1)
        throw GradeTooHighException();
}

void    Bureaucrat::decrement() {
    grade++;
    if (grade > 150)
        throw GradeTooLowException();
}

void    Bureaucrat::signForm(AForm& form) const {
    try {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << this->name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const& form) {
    try
    {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
    out << bureaucrat.getName() << ",  bureaucrat grade " << bureaucrat.getGrade()  << "." << std::endl;
    return out;
}