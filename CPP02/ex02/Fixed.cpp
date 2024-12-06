/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:30:21 by tiima             #+#    #+#             */
/*   Updated: 2024/11/22 14:26:07 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

const   int Fixed::rawBits = 8;

Fixed::Fixed() : fixedPoint(0) {}

Fixed::~Fixed () {}

Fixed::Fixed (const Fixed& other) {
    *this = other;
}

Fixed&  Fixed::operator=(const Fixed& other) {
    if (this != &other)
        fixedPoint = other.fixedPoint;
    return *this;
}

Fixed::Fixed(const int p) : fixedPoint(p * (1 << rawBits)) /* this is equivalent to fixedPoint = p * (pow(2, 8)) */{}

Fixed::Fixed(const float p) : fixedPoint(roundf(p * (1 << rawBits))) {}

int Fixed::getRawBits( void ) const {
    return (fixedPoint);
}

void    Fixed::setRawBits( int const raw ) {
    fixedPoint = raw;
}

int     Fixed::toInt( void ) const {
    return (fixedPoint / (1 << rawBits));
}

float     Fixed::toFloat( void ) const {
    return (static_cast<float>(fixedPoint) / (1 << rawBits));
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
    returned.setRawBits(((getRawBits() * other.getRawBits())) / (1 << rawBits));
    return (returned);
}

Fixed   Fixed::operator/(const Fixed& other) const {
    Fixed returned;
    returned.setRawBits((getRawBits() * (1 << rawBits)) / other.getRawBits());
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