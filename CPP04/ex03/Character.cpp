# include "Character.hpp"

Character::Character() : _name("defaulf") {
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(std::string const& name) : _name(name) {
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name) {
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i];
        else
            inventory[i] = NULL;
    }
}

Character::~Character() {
    for (int i = 0; i < 4; i++)
        if (inventory[i])
            delete inventory[i];
}

Character&  Character::operator=(const Character& other) {
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (other.inventory[i])
            {
                delete inventory[i];
                inventory[i] = other.inventory[i]->clone();
            }
            else
                inventory[i] = NULL;
        }
    }
    return *this;
}

std::string const&  Character::getName() const { return _name; }

void    Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            return ;
        }
    }
}

void    Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx] = NULL;
}

void    Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
}