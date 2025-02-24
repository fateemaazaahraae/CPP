#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;

    public:
        //! O.C.F
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm&  operator=(const ShrubberyCreationForm& other);

        //! File exception
        class fileException : std::exception {
            public:
                virtual const char* what() const throw();
        };

        //! Member function
        void    shrubberyAction() const;
        void	execute(Bureaucrat const& executor) const;
};

#endif