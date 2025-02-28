#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
    private :
        std::string Name;
        int HitPoints;
        int EnergyPoints;
        int AttackDamage;

    public:
        ClapTrap();
        ~ClapTrap();
        ClapTrap(const ClapTrap& other);
        ClapTrap&   operator=(const ClapTrap& other);
        ClapTrap(std::string str);

        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};

#endif