/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:30:21 by tiima             #+#    #+#             */
/*   Updated: 2024/11/23 16:21:52 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

const   int Fixed::fractionalBits = 8;

Fixed::Fixed() : fixedPoint(0) {}

Fixed::~Fixed () {}

Fixed::Fixed (const Fixed& other) {
    fixedPoint = other.fixedPoint;
}

Fixed&  Fixed::operator=(const Fixed& other) {
    if (this != &other)
        fixedPoint = other.fixedPoint;
    return *this;
}

Fixed::Fixed(const int p) : fixedPoint(p * (1 << fractionalBits)) /* this is equivalent to fixedPoint = p * (pow(2, 8)) */{}

Fixed::Fixed(const float p) : fixedPoint(roundf(p * (1 << fractionalBits))) {}

int Fixed::getRawBits( void ) const {
    return (fixedPoint);
}

void    Fixed::setRawBits( int const raw ) {
    fixedPoint = raw;
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

bool    Fixed::operator>( const Fixed& other ) const {
    return (getRawBits() > other.getRawBits());
}

bool    Fixed::operator>=( const Fixed& other ) const {
    return (getRawBits() >= other.getRawBits());
}

bool    Fixed::operator<( const Fixed& other ) const {
    return (getRawBits() < other.getRawBits());
}

bool    Fixed::operator<=( const Fixed& other ) const {
    return (getRawBits() <= other.getRawBits());
}

bool    Fixed::operator==( const Fixed& other ) const {
    return (getRawBits() == other.getRawBits());
}

bool    Fixed::operator!=( const Fixed& other ) const {
    return (getRawBits() != other.getRawBits());
}

Fixed   Fixed::operator+(const Fixed& other) const {
    Fixed returned;
    returned.setRawBits(getRawBits() + other.getRawBits());
    return (returned);
}

Fixed   Fixed::operator-(const Fixed& other) const {
    Fixed returned;
    returned.setRawBits(getRawBits() - other.getRawBits());
    return (returned);
}

Fixed   Fixed::operator*(const Fixed& other) const {
    Fixed returned;
    returned.setRawBits(((getRawBits() * other.getRawBits())) / (1 << fractionalBits));
    return (returned);
}

Fixed   Fixed::operator/(const Fixed& other) const {
    Fixed returned;
    returned.setRawBits((getRawBits() * (1 << fractionalBits)) / other.getRawBits());
    return (returned);
}

Fixed&  Fixed::operator++() {
    fixedPoint++;
    return *this;
}

Fixed&  Fixed::operator--() {
    fixedPoint--;
    return *this;
}

Fixed  Fixed::operator++(int) {
    Fixed   tmp;

    tmp = *this;
    this->fixedPoint++;
    return (tmp);
}

Fixed  Fixed::operator--(int) {
    Fixed   tmp;

    tmp = *this;
    this->fixedPoint--;
    return (tmp);
}

Fixed&  Fixed::min(Fixed& a, Fixed& b) {
    return (a < b ? a : b);
}

Fixed&  Fixed::max(Fixed& a, Fixed& b) {
    return (a > b ? a : b);
}

const Fixed&  Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b ? a : b);
}

const Fixed&  Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b ? a : b);
}