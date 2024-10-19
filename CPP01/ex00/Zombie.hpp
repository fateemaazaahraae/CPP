#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
    private:
        std::string name;
    public:
        Zombie(std::string ZombieName);
        ~Zombie(void);

        void    announce( void );
};

#endif