#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
    protected :
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
        ClapTrap(std::string str, int _hitPoint, int _energy, int _attack);

        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        int     getHit() const;
        int     getEnergy() const;
        int     getAttack() const;
};

#endif
