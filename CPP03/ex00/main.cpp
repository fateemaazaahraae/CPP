/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:33:12 by tiima             #+#    #+#             */
/*   Updated: 2024/11/24 14:46:59 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap robot("Clappy");

    std::cout << "\n--- Initial Status ---\n";
    robot.attack("Target1");
    robot.takeDamage(5);
    robot.beRepaired(3);

    std::cout << "\n--- Taking Too Much Damage ---\n";
    robot.takeDamage(20);

    std::cout << "\n--- Trying to Attack with Zero HP ---\n";
    robot.attack("Target2");

    std::cout << "\n--- Trying to Repair with Zero HP ---\n";
    robot.beRepaired(5);

    return 0;
}
