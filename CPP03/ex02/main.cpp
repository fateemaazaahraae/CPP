/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:33:12 by tiima             #+#    #+#             */
/*   Updated: 2024/11/30 10:58:32 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    // Create ClapTrap instance
    ClapTrap clap("Clappy");
    clap.attack("Enemy");
    clap.takeDamage(10);
    clap.beRepaired(5);
    
    std::cout << std::endl << "-------------------------------------" << std::endl << std::endl;

    // Create ScavTrap instance
    ScavTrap scav("Scavvy");
    scav.attack("Enemy1");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();  // Special function for ScavTrap
    
    std::cout << std::endl << "-------------------------------------" << std::endl << std::endl;

    // Create FragTrap instance
    FragTrap frag("Fraggy");
    frag.attack("Enemy2");
    frag.takeDamage(30);
    frag.beRepaired(15);
    frag.highFivesGuys();  // Special function for FragTrap
    
    return 0;
}

