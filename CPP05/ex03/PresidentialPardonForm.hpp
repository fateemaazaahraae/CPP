#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private :
        std::string _target;

    public :
        //! O.C.F
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

        //! Member function
        void    pardonAction() const;
        void    execute(Bureaucrat const& executor) const;
        static AForm*  createForm(std::string target);
};

#endif