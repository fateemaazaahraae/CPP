/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:19:43 by tiima             #+#    #+#             */
/*   Updated: 2024/12/31 15:24:55 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat() {
    std::cout << "The Cat Default Constructor called" << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::~Cat() {
    delete brain;
    std::cout << "The Cat Deconstructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "The Cat Copy Constructor called" << std::endl;
}

Cat&    Cat::operator=(const Cat& other) {
    std::cout << "The Cat Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        type = other.type;
        *brain = *other.brain; 
    }
    return *this;
}

void    Cat::makeSound() const {
    std::cout << "Meow Meow.." << std::endl;
}

void Cat::setBrainIdea(const std::string& idea, int index) {
    brain->setIdea(idea, index);
}

std::string Cat::getBrainIdea(int index) const {
    return brain->getIdea(index);
}