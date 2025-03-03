# include "ShrubberyCreationForm.hpp"

//! O.C.F
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

//! File exception
const char* ShrubberyCreationForm::fileException::what() const throw() {
    return "Error, Cannot open the file";
}

//! Member functions
void    ShrubberyCreationForm::shrubberyAction() const
{
    std::string file = _target + "_shrubbery";
    std::ofstream   outFile(file.c_str());
    
    if (outFile.is_open())
    {
        outFile << "      ^\n     ^^^\n    ^^^^^\n   ^^^^^^^\n     ||\n";
        std::cout << "Shrubbery file created: " << file << std::endl;
        outFile.close();
    }
    else
        throw fileException();
}

void    ShrubberyCreationForm::execute(Bureaucrat const& executor) const 
{
    if (getSigned() && executor.getGrade() <= getGradeToExec())
        shrubberyAction();
    else if (!getSigned())
        throw GradeSignException();
    else
        throw GradeTooLowException();
}

AForm*  ShrubberyCreationForm::createForm(std::string target) { return new ShrubberyCreationForm(target); }