/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:26:32 by tiima             #+#    #+#             */
/*   Updated: 2024/12/30 09:53:33 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default", 100, 100, 30) {
    std::cout << "The FragTrap Default Constructor called !." << std::endl;
}

FragTrap::FragTrap(std::string str) : ClapTrap(str, 100, 100, 30) {
    std::cout << "The FragTrap Parameterized Constructor called !." << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "The FragTrap Destructor called !." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "The FragTrap Copy Constructor called !." << std::endl;
    *this = other;
}

FragTrap&   FragTrap::operator=(const FragTrap& other) {
    std::cout << "The FragTrap Copy Assignment Operator called >" << std::endl;
    if (this != &other)
    {
        Name = other.Name;
        HitPoints = other.HitPoints;
        EnergyPoints = other.EnergyPoints;
        AttackDamage = other.AttackDamage;
    }
    return *this;
}

void    FragTrap::highFivesGuys() {
    std::cout << "Give me a high five, guys! Let's rock this!" << std::endl;
}