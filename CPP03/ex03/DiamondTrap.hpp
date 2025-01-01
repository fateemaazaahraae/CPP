#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
    protected :
        std::string Name;
    public :
        DiamondTrap();
        DiamondTrap(std::string str);
        ~DiamondTrap();
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap&    operator=(const DiamondTrap& other);

        void    attack(const std::string& str);
        void    whoAmI();
};

#endif
