#ifndef INTER_HPP
# define INTER_HPP

# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern {
    public :
        //! O.C.F
        Intern();
        ~Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);

        AForm*  makeForm(std::string formName, std::string target);

        //! Exceptions
        class ErrMessage : public std::exception {
            public :
                virtual const char* what() const throw();
        };
};

#endif