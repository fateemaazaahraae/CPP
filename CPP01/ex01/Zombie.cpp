/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 09:56:03 by tiima             #+#    #+#             */
/*   Updated: 2024/10/19 10:19:56 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie( std::string ZombieName ) : name( ZombieName ) {}

Zombie::~Zombie( void ) {
    std::cout << name << " is destroyed !" << std::endl;
}

void    Zombie::announce( void ) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName( std::string ZombieName ) {
    name = ZombieName;
}