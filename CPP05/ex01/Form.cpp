# include "Form.hpp"

//! O.C.F
Form::Form() : _name("tiima"), _signed(false), _gradeToSign(150), _gradeToExec(150) {}

Form::~Form() {}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec) : 
    _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
        if (_gradeToExec < 1 || _gradeToSign < 1)
            throw GradeTooHighException();
        if (_gradeToExec > 150 || _gradeToSign > 150)
            throw GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed),
    _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {}

Form&   Form::operator=(const Form& other) {
    _signed = other._signed;
    return *this;
}

//! My exceptions
const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too HIGH";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too LOW";
}

//! Getters
const std::string& Form::getName() const { return _name; }
bool  Form::getSigned() const { return _signed; }
int   Form::getGradeToSign() const { return _gradeToSign; }
int   Form::getGradeToExec() const { return _gradeToExec; }

std::ostream&   operator<<(std::ostream& out, const Form& form)
{
    out << "Form name: " << form.getName() << std::endl;
    out << "Is Signed: " << form.getSigned() << std::endl;
    out << "Grade To Sign: " << form.getGradeToSign() << std::endl;
    out << "Grade To Execute: " << form.getGradeToExec() << std::endl;
    return out;
}

void    Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeToSign)
        _signed = true;
    else
        throw GradeTooLowException();
}