/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:08:16 by tiima             #+#    #+#             */
/*   Updated: 2024/12/03 11:17:28 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "The Dog Default Constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "The Dog Deconstructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "The Dog Copy Constructor called" << std::endl;
    *this = other;
}

Dog&    Dog::operator=(const Dog& other) {
    std::cout << "The Dog Copy assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

void    Dog::makeSound() const {
    std::cout << "Haeo Haeo.." << std::endl;
}