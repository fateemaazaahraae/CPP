/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:26:51 by tiima             #+#    #+#             */
/*   Updated: 2024/11/25 11:25:33 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default") {
    std::cout << "The ScavTrap Default constructor called !!" << std::endl;
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;   
}

ScavTrap::ScavTrap( std::string str ) : ClapTrap(str) {
    std::cout << "The ScavTrap Parameterized constructor called !!" << std::endl;
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;   
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

void    ScavTrap::guardGate() {
    std::cout << "The ScavTrap is now in Gate keeper mode." << std::endl;
}