/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:33:12 by tiima             #+#    #+#             */
/*   Updated: 2024/12/01 11:25:57 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


int main() {
    DiamondTrap dt1("Diamond1");
    dt1.attack("Enemy");
    dt1.whoAmI();

    std::cout << "------------------------------------------------------------------\n";

    DiamondTrap dt2(dt1); // Test copy constructor
    dt2.whoAmI();

    std::cout << "------------------------------------------------------------------\n";

    DiamondTrap dt3;
    dt3 = dt1; // Test assignment operator
    dt3.whoAmI();

    return 0;
}


