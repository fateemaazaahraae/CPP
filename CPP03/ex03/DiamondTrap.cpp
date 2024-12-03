/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:25:48 by tiima             #+#    #+#             */
/*   Updated: 2024/12/01 11:24:45 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), Name("Default") {
    HitPoints = FragTrap::HitPoints;
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FragTrap::AttackDamage;
    std::cout << "The DiamondTrap Default Constructor called >" << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name) : ClapTrap(_name + "_clap_name"), ScavTrap(_name), FragTrap(_name), Name(_name) {
    HitPoints = FragTrap::HitPoints;
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FragTrap::AttackDamage;
    std::cout << "The DiamondTrap Parameterized Constructor called >" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "The DiamondTrap Destructor called >" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
    std::cout << "The DiamondTrap Copy Constructor called >" << std::endl;
    *this = other;
}

DiamondTrap&    DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "The DiamondTrap Copy Assignment Operator called >" << std::endl;
    if (this != &other)
    {
        ClapTrap::Name = other.Name + "_clap_name";
        Name = other.Name;
        HitPoints = other.HitPoints;
        EnergyPoints = other.EnergyPoints;
        AttackDamage = other.AttackDamage;
    }
    return *this;
}

void    DiamondTrap::attack(const std::string& str)
{
    ScavTrap::attack(str);
}

void    DiamondTrap::whoAmI() {
    std::cout << "The DiamondTrap's Name : " << Name << std::endl << "The ClapTrap's Name : " << ClapTrap::Name << std::endl;
}