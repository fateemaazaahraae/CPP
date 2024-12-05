#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
    protected :
        std::string type;

    public :
        Animal(void);
        virtual ~Animal();
        Animal( const Animal& other );
        Animal& operator=( const Animal& other );

        std::string getType() const;
        void    setType( std::string _type );
        virtual void    makeSound( void ) const;

};

#endif