#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <fstream>
# include <cstdlib>

class AForm {
    private:
        const std::string   _name;
        bool        _signed;
        const int   _gradeToSign;
        const int   _gradeToExec;

    public:
        //! O.C.F
        AForm();
        virtual ~AForm();
        AForm(const std::string name, const int gradeToSign, const int gradeToExec);
        AForm(const AForm& other);
        AForm&   operator=(const AForm& other);

        //! My exceptions
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeSignException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        //! Getters
        const std::string& getName() const;
        bool  getSigned() const;
        int   getGradeToSign() const;
        int   getGradeToExec() const;

        void    beSigned(const Bureaucrat& bureaucrat);

        //! Pure virtual func
        virtual void    execute(Bureaucrat const & executor) const = 0;

};

std::ostream& operator<<(std::ostream& out, const AForm& form); 

#endif