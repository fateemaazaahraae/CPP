/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:26:34 by tiima             #+#    #+#             */
/*   Updated: 2024/10/21 17:28:43 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name), weapon(NULL) {}

void    HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
}

void    HumanB::attack() {
    if (weapon)
        std::cout << name << " attack with " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no attack with!" << std::endl;
}