/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:33:29 by fbazaz            #+#    #+#             */
/*   Updated: 2024/10/14 15:14:17 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

void    Adding(PhoneBook User)
{
    std::cout << "Enter the first name : ";
    std::getline(std::cin, User.);
}

int main()
{
    std::string cmd;
    PhoneBook   User;
    
    while (1)
    {
        std::cout << "Enter the command (ADD, SEARCH or EXIT) : " << std::endl;
        std::getline(std::cin, cmd);
        if (cmd == "EXIT")
        {
            std::cout << "Exiting program.." << std::endl;
            break;
        }
        if (cmd.empty())
        {
            std::cout << "The string is empty." << std::endl;
            continue;
        }
        if (cmd == "ADD")
            Adding(User);
    }
}