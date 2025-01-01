/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:33:12 by tiima             #+#    #+#             */
/*   Updated: 2025/01/01 08:44:09 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main ()
{
	std::cout << "\n### TESTING SCAVTRAP ###\n" << std::endl;
	{
		std::cout << "-------- Constructing -------" << std::endl;
		ScavTrap c;
		ScavTrap d("Savage");

		std::cout << "-------- Testing ---------" << std::endl;
		c.attack("CloneTrap");
		c.beRepaired(22);
		c.takeDamage(21);
		c.beRepaired(22);
		c.guardGate();
		c.guardGate();
        std::cout << "\n^^^^^^^^^^^^^^^^^^^^\n\n";
		d.attack("Savage-clone");
		d.takeDamage(101);
		d.takeDamage(15);
		d.attack("ScavTrap-clone");
		std::cout << "-------- Destructing ----------" << std::endl;
	}
	return (0);
}
