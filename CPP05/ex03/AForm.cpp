# include "AForm.hpp"

//! O.C.F
AForm::AForm() : _name("tiima"), _signed(false), _gradeToSign(150), _gradeToExec(150) {}

AForm::~AForm() {}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExec) : 
    _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
        if (_gradeToExec < 1 || _gradeToSign < 1)
            throw GradeTooHighException();
        if (_gradeToExec > 150 || _gradeToSign > 150)
            throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed),
    _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {}

AForm&   AForm::operator=(const AForm& other) {
    _signed = other._signed;
    return *this;
}

//! My exceptions
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too HIGH";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too LOW";
}

const char* AForm::GradeSignException::what() const throw() {
    return "The Form isn't Signed";
}

//! Getters
const std::string& AForm::getName() const { return _name; }
bool  AForm::getSigned() const { return _signed; }
int   AForm::getGradeToSign() const { return _gradeToSign; }
int   AForm::getGradeToExec() const { return _gradeToExec; }

std::ostream&   operator<<(std::ostream& out, const AForm& form)
{
    out << "AForm name: " << form.getName() << std::endl;
    out << "Is Signed: " << form.getSigned() << std::endl;
    out << "Grade To Sign: " << form.getGradeToSign() << std::endl;
    out << "Grade To Execute: " << form.getGradeToExec() << std::endl;
    return out;
}

void    AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeToSign)
        _signed = true;
    else
        throw GradeTooLowException();
}