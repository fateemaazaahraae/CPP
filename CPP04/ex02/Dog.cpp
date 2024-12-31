/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:08:16 by tiima             #+#    #+#             */
/*   Updated: 2024/12/31 15:25:16 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog() {
    std::cout << "The Dog Default Constructor called" << std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::~Dog() {
    delete brain;
    std::cout << "The Dog Deconstructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "The Dog Copy Constructor called" << std::endl;
}

Dog&    Dog::operator=(const Dog& other) {
    std::cout << "The Dog Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        type = other.type;
        *brain = *other.brain;
    }
    return *this;
}

void    Dog::makeSound() const {
    std::cout << "Haeo Haeo.." << std::endl;
}

void Dog::setBrainIdea(const std::string& idea, int index) {
    brain->setIdea(idea, index);
}

std::string Dog::getBrainIdea(int index) const {
    return brain->getIdea(index);
}
