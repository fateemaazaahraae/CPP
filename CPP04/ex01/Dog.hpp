#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain*  brain;

    public:
        Dog();
        Dog(const Dog& other);
        Dog&    operator=(const Dog& other);
        ~Dog();

        void    makeSound( void ) const;
        void    setBrainIdea(const std::string& idea, int index);
        std::string getBrainIdea(int index) const;
};

#endif