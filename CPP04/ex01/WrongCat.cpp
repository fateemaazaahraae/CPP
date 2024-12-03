/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:24:13 by tiima             #+#    #+#             */
/*   Updated: 2024/12/03 11:29:13 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "Cat <WRONG>";
    std::cout << "The WrongCat Default Constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "The WrongCat Deconstructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "The WrongCat Copy Constructor called" << std::endl;
    *this = other;
}

WrongCat&    WrongCat::operator=(const WrongCat& other) {
    std::cout << "The WrongCat Copy assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

void    WrongCat::makeSound() const {
    std::cout << "Meow Meow.." << std::endl;
}