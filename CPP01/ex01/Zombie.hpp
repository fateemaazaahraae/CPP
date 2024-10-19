#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <limits>

class Zombie {
    private:
        std::string name;
    public:
        Zombie();
        Zombie( std::string ZombieName );
        ~Zombie( void );

        void    announce( void );
        void    setName( std::string ZombieName );
};

#endif