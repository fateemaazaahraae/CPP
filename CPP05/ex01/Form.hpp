#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form {
    private:
        const std::string   _name;
        bool    _signed;
        const int   _gradeToSign;
        const int   _gradeToExec;

    public:
        //! O.C.F
        Form();
        ~Form();
        Form(const std::string name, const int gradeToSign, const int gradeToExec);
        Form(const Form& other);
        Form&   operator=(const Form& other);

        //! My exceptions
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        //! Getters
        const std::string& getName() const;
        bool  getSigned() const;
        int   getGradeToSign() const;
        int   getGradeToExec() const;

        void    beSigned(const Bureaucrat& bureaucrat);

};

std::ostream& operator<<(std::ostream& out, const Form& form); 

#endif