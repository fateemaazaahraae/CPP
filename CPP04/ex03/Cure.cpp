# include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

Cure&    Cure::operator=(const Cure& other) {
    (void)other;
    return *this;
}

AMateria*   Cure::clone() const { 
    return new Cure(); 
}

void    Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}