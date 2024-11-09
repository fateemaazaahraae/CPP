# include "Zombie.hpp"

Zombie::Zombie(std::string ZombieName) : name(ZombieName) {}

void    Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}