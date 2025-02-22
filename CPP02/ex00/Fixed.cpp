/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:25:01 by tiima             #+#    #+#             */
/*   Updated: 2024/11/15 12:12:51 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

const   int Fixed::fractionalBits = 8;

Fixed::Fixed() : fixedPoint(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed () {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed (const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed&  Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        fixedPoint = other.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (fixedPoint);
}

void    Fixed::setRawBits( int const raw ) {
    fixedPoint = raw;
    std::cout << "setRawBits member function called" << std::endl;
}