/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:26:51 by tiima             #+#    #+#             */
/*   Updated: 2025/01/01 08:43:35 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default", 100, 50, 20) {
    std::cout << "The ScavTrap Default constructor called !!" << std::endl;  
}

ScavTrap::ScavTrap( std::string str ) : ClapTrap(str, 100, 50, 20) {
    std::cout << "The ScavTrap Parameterized constructor called !!" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "The ScavTrap Destructor called !!" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& other ) : ClapTrap(other) {
    std::cout << "The ScavTrap Copy Constructor called !!" << std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& other ) {
    std::cout << "The ScavTrap Copy assignment operator called !!" << std::endl;
    if (this != &other)
    {
        Name = other.Name;
        HitPoints = other.HitPoints;
        EnergyPoints = other.EnergyPoints;
        AttackDamage = other.AttackDamage;
    }
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (EnergyPoints > 0 && HitPoints > 0)
    {
        std::cout << "ScavTrap " << Name << " attacks " << target << " causing " << AttackDamage << " points of damage" << std::endl;
        EnergyPoints--;
        return ;
    }
    if (EnergyPoints <= 0)
        std::cout << "ScavTrap " << Name << " cannot attack because he has no EnergyPoint !" << std::endl;
    else
        std::cout << "ScavTrap " << Name << " cannot attack because he has no HitPoints !" << std::endl;
}

void    ScavTrap::guardGate() {
    std::cout << "The ScavTrap is now in Gate keeper mode." << std::endl;
}