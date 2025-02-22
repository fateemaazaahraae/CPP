 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:37:20 by tiima             #+#    #+#             */
/*   Updated: 2024/11/19 10:19:30 by tiima            ###   ########.fr       */
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
        fixedPoint = other.fixedPoint;
    return *this;
}

Fixed::Fixed(const int p) : fixedPoint(p * (1 << fractionalBits)) /* this is equivalent to fixedPoint = p * (pow(2, 8)) */{ 
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float p) : fixedPoint(roundf(p * (1 << fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (fixedPoint);
}

void    Fixed::setRawBits( int const raw ) {
    fixedPoint = raw;
    std::cout << "setRawBits member function called" << std::endl;
}

int     Fixed::toInt( void ) const {
    return (fixedPoint / (1 << fractionalBits));
}

float     Fixed::toFloat( void ) const {
    return ((1.0 * fixedPoint) / (1 << fractionalBits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}