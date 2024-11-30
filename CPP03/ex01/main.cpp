/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:33:12 by tiima             #+#    #+#             */
/*   Updated: 2024/11/30 10:38:26 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// int main()
// {
//     ScavTrap nino("JJKK");

//     nino.attack("Enemy1");
//     nino.takeDamage(9);
//     nino.beRepaired(1);
//     return 0;
// }

int main() {
    ClapTrap clap1;
    ClapTrap clap2("Clappy");

    clap2.attack("enemy");
    clap2.takeDamage(3);
    clap2.beRepaired(2);
    clap2.takeDamage(20);

    ScavTrap scav1;
    ScavTrap scav2("Scavvy");

    std::cout << "-----------------\n";
    ScavTrap scav3(scav2);

    scav2.attack("enemy");
    scav2.takeDamage(30);
    scav2.beRepaired(10);
    scav2.takeDamage(120);

    scav2.guardGate();

    scav3 = scav1;

    return 0;
}
