/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:48:10 by tiima             #+#    #+#             */
/*   Updated: 2024/12/05 13:22:12 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

int main(int ac, char *av[])
{
    Harl    harl;
    int     levelIndex;

    if (ac != 2)
    {
        std::cout << "Enter one argument!" << std::endl;
        return (1);
    }
    levelIndex = harl.getLevelIndex(av[1]);
    switch (levelIndex)
    {
        case 0:
            harl.complain("DEBUG");
            break;
        case 1:
            harl.complain("INFO");
            break;
        case 2:
            harl.complain("WARNING");
            break;
        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}