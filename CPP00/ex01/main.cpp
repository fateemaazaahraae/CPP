/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:33:29 by fbazaz            #+#    #+#             */
/*   Updated: 2024/10/16 15:18:07 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

void    FillUser(PhoneBook& User)
{
    Contact NewUser;

    GetInputFirstName(NewUser);
    GetInputLastName(NewUser);
    GetInputNickName(NewUser);
    GetInputPhoneNumber(NewUser);
    GetInputDarkestSecret(NewUser);
    User.AddContact(NewUser);
}

int main()
{
    std::string cmd;
    PhoneBook   User;
    
    while (1)
    {
        std::cout << "Enter the command (ADD, SEARCH or EXIT) : " << std::endl;
        std::getline(std::cin, cmd);
        if (cmd.empty())
        {
            std::cout << "The string is empty." << std::endl;
            continue;
        }
        if (cmd == "EXIT")
        {
            std::cout << "Exiting program.." << std::endl;
            break;
        }
        else if (cmd == "ADD")
            FillUser(User);
        else if (cmd == "SEARCH")
            User.SearchContact();
        else
            std::cerr << "Unknown Command!" << std::endl;
    }
    std::cout << "See you !!" << std::endl;
    return (0);
}