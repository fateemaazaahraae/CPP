/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:48:07 by tiima             #+#    #+#             */
/*   Updated: 2024/12/05 13:21:39 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

void    Harl::debug( void ) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl << std::endl;
}

void    Harl::info( void ) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl << std::endl;
}

void    Harl::warning( void ) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void    Harl::error( void ) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

int     Harl::getLevelIndex(std::string level) {
    int i = 0;
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    while (i < 4)
    {
        if (levels[i] == level)
            return (i);
        i++;
    }
    return (-1);
}

void    Harl::complain(std::string level)
{
    void    (Harl::*harl_actions[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    int     index;

    index = getLevelIndex(level);
    while (index < 4)
    {
        (this->*harl_actions[index])();
        index++;
    }
}