/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:22:31 by tiima             #+#    #+#             */
/*   Updated: 2024/12/03 11:22:36 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "The WrongAnimal Default Constructor called !" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "The WrongAnimal Destructor called !" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    std::cout << "The WrongAnimal Copy Constructor called !" << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "The WrongAnimal Copy Assignment operator called !" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

std::string WrongAnimal::getType() const {
    return type;
}

void    WrongAnimal::setType(std::string _type) {
    type = _type;
}

void    WrongAnimal::makeSound( void ) const {
    std::cout << "The WrongAnimal make sound" << std::endl;
}