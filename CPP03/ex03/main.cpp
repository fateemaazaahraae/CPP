/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:33:12 by tiima             #+#    #+#             */
/*   Updated: 2024/12/31 10:59:59 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap	b("Morgan");
    
	b.whoAmI();
	std::cout << "===" << std::endl;
	b.takeDamage(3);
	b.takeDamage(20);
	b.beRepaired(3);
	b.attack("Eric");
	b.attack("Eric");
	b.attack("Eric");
	b.beRepaired(100);
	b.attack("Eric");
    b.guardGate();
    b.highFivesGuys();

    return 0;
}


