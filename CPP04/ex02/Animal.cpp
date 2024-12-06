/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:04:22 by tiima             #+#    #+#             */
/*   Updated: 2024/12/03 11:17:13 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "The Animal Default Constructor called !" << std::endl;
}

Animal::~Animal() {
    std::cout << "The Animal Destructor called !" << std::endl;
}

Animal::Animal(const Animal& other) {
    std::cout << "The Animal Copy Constructor called !" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "The Animal Copy Assignment operator called !" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

std::string Animal::getType() const {
    return type;
}

void    Animal::setType(std::string _type) {
    type = _type;
}

void    Animal::makeSound( void ) const {
    std::cout << "The Animal make sound" << std::endl;
}