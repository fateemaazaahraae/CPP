/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:19:43 by tiima             #+#    #+#             */
/*   Updated: 2024/12/03 11:17:22 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "The Cat Default Constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "The Cat Deconstructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "The Cat Copy Constructor called" << std::endl;
    *this = other;
}

Cat&    Cat::operator=(const Cat& other) {
    std::cout << "The Cat Copy assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

void    Cat::makeSound() const {
    std::cout << "Meow Meow.." << std::endl;
}