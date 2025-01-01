/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:33:12 by tiima             #+#    #+#             */
/*   Updated: 2025/01/01 08:44:50 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    std::cout << "### TESTING FRAGTRAP ###\n" << std::endl;
    FragTrap frag("Fraggy");
    frag.attack("Enemy2");
    frag.takeDamage(30);
    frag.beRepaired(15);
    frag.highFivesGuys();  // Special function for FragTrap
    
    return 0;
}

