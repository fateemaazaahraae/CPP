/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:33:09 by tiima             #+#    #+#             */
/*   Updated: 2024/11/30 11:00:38 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("Default"), HitPoints(10), EnergyPoints(10), AttackDamage(0) {
    std::cout << "The ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string str ) : Name(str), HitPoints(10), EnergyPoints(10), AttackDamage(0) {
    std::cout << "The ClapTrap Parameterized constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "The ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& other ) : Name(other.Name), HitPoints(other.HitPoints), EnergyPoints(other.EnergyPoints), AttackDamage(other.AttackDamage) {
    std::cout << "The ClapTrap Copy Constructor called" << std::endl;
}

ClapTrap&   ClapTrap::operator=( const ClapTrap& other ) {
    std::cout << "The ClapTrap Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Name = other.Name;
        HitPoints = other.HitPoints;
        EnergyPoints = other.EnergyPoints;
        AttackDamage = other.AttackDamage;
    }
    return *this;
}

void ClapTrap::attack( const std::string& target ) {
    if (EnergyPoints > 0 && HitPoints > 0)
    {
        std::cout << "ClapTrap " << Name << " attacks " << target << " causing " << AttackDamage << " points of damage" << std::endl;
        EnergyPoints--;
        return ;
    }
    std::cout << "ClapTrap " << Name << " cannot attack because he has no EnergyPoints or HitPoints left !" << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount ) {
    if (HitPoints <= 0)
    {
        std::cout << "The ClapTrap lose all Hitpoints" << std::endl;
        return ;
    }
    HitPoints -= amount;
    std::cout << "ClapTrap " << Name << " takes a damage of " << amount << std::endl;
    if (HitPoints < 0) 
    {
        HitPoints = 0;
        std::cout << "The ClapTrap " << Name << " lose all his HitPoints" << std::endl;
    }
    std::cout << "HitPoints -> " << HitPoints << std::endl;
    std::cout << "EnergyPoints -> " << EnergyPoints << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount ) {
    if (EnergyPoints > 0 && HitPoints > 0)
    {
        HitPoints += amount;
        EnergyPoints--;
        std::cout << "ClapTrap " << Name << " repairs itself by " << amount << " points!" << std::endl;
        std::cout << "HitPoints -> " << HitPoints << std::endl;
        std::cout << "EnergyPoints -> " << EnergyPoints << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << Name << " cannot attack because he has no EnergyPoints or HitPoints left !" << std::endl;
}
