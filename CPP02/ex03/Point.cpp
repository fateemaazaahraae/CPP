/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:37:11 by tiima             #+#    #+#             */
/*   Updated: 2024/11/23 13:55:31 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point( float x1, float y1 ) : x(x1), y(y1) {}

Point::Point( const Point& other ) : x(other.x), y(other.y) {}

Point&  Point::operator=( const Point& other ) {
    if (this != &other)
        std::cerr << "Cannot assign value to Const attributes" << std::endl;
    return (*this);
}

Point::~Point() {}

const   Fixed& Point::getX( void ) const {
    return (x);
}

const   Fixed& Point::getY( void ) const {
    return (y);
}