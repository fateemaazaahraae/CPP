#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class AForm;

class Bureaucrat
{
    private:
        const std::string name;
        int                 grade;
    
    public:
        //! O.C.F
        Bureaucrat();
        Bureaucrat(const std::string Name, int Grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);

        //! The exceptions
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        //! Getters
        std::string const& getName() const;
        int getGrade() const;

        //! Member functions
        void    increment();
        void    decrement();
        void    signForm(AForm& form) const;
        void    executeForm(AForm const& form);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);


#endif