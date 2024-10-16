/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_utils.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:55:49 by fbazaz            #+#    #+#             */
/*   Updated: 2024/10/16 11:29:31 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

void    GetInputFirstName(Contact& NewUser)
{
    std::string input;

    while (1)
    {
        std::cout << "Enter the FirstName: ";
        std::getline(std::cin, input);
        if (input.empty())
        {
            std::cout << "Invalid FirstName" << std::endl;
            continue;
        }
        else
            break;
    }
    NewUser.SetFirstName(input);
}

void    GetInputLastName(Contact& NewUser)
{
    std::string input;

    while (1)
    {
        std::cout << "Enter the LastName: ";
        std::getline(std::cin, input);
        if (input.empty())
        {
            std::cout << "Invalid LastName" << std::endl;
            continue;
        }
        else
            break;
    }
    NewUser.SetLastName(input);
}

void    GetInputNickName(Contact& NewUser)
{
    std::string input;

    while (1)
    {
        std::cout << "Enter the NickName: ";
        std::getline(std::cin, input);
        if (input.empty())
        {
            std::cout << "Invalid NickName" << std::endl;
            continue;
        }
        else
            break;
    }
    NewUser.SetNickName(input);
}

void    GetInputPhoneNumber(Contact& NewUser)
{
    std::string input;

    while (1)
    {
        std::cout << "Enter the PhoneNumber: ";
        std::getline(std::cin, input);
        if (input.empty())
        {
            std::cout << "Invalid PhoneNumber" << std::endl;
            continue;
        }
        else
            break;
    }
    NewUser.SetPhoneNumber(input);
}

void    GetInputDarkestSecret(Contact& NewUser)
{
    std::string input;

    while (1)
    {
        std::cout << "Enter the DarkestSecret: ";
        std::getline(std::cin, input);
        if (input.empty())
        {
            std::cout << "Invalid DarkestSecret" << std::endl;
            continue;
        }
        else
            break;
    }
    NewUser.SetDarkestSecret(input);
}
