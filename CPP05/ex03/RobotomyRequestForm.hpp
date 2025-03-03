#ifndef ROBOTTOMYREQUESTFORM_HPP
# define ROBOTTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;
    
    public:
        //! O.C.F
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm&    operator=(const RobotomyRequestForm& other);

        //! Member functions
        void    robotAction() const;
        void	execute(Bureaucrat const& executor) const;
        static AForm*  createForm(std::string target);
};

#endif