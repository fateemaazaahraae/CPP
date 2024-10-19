/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:55:11 by fbazaz            #+#    #+#             */
/*   Updated: 2024/10/18 11:10:30 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"
# include <limits>

Contact PhoneBook::GetContact(int i) const {
    if (i >= 0 && i < 8)
        return (contacts[i]);
    std::cerr << "Invalid Index! connot get the contact" << std::endl;
    return Contact();
}

void PhoneBook::SetContact(int i, Contact& NewUser) {
    if (i >= 0 && i < 8)
        contacts[i] = NewUser;
    else
        std::cerr << "Invalid Index! cannot set the contact" << std::endl;
}

int PhoneBook::GetIndex() const {
    return (index);
}

void    PhoneBook::SetIndex(int i) {
    index = i;
}

void    PhoneBook::AddContact(Contact& element) {
    if (GetIndex() == 8)
        SetIndex(0);
    SetContact(GetIndex(), element);
    SetIndex(GetIndex() + 1);
}

std::string ColumnFormat(const std::string& field) {
    if (field.length() > 10)
        return (field.substr(0, 9) + ".");
    else
        return (std::string(10 - field.length(), ' ') + field);
}

void    PhoneBook::SearchContact() {
    int i; 
    int j;

    if (contacts[0].GetFirstName().empty())
    {
        std::cerr << "Empty PhoneBook !!" << std::endl;
        return ;
    }
    std::cout << std::endl << "     Index|First Name| Last Name|  Nickname|" << std::endl;
    i = 0;
    while (i < 8)
    {
        if (!contacts[i].GetFirstName().empty()) // 0 -> isn't empty
        {
            std::cout << "--------------------------------------------" << std::endl;
            std::cout << std::setw(10) << i << "|";
            std::cout << ColumnFormat(contacts[i].GetFirstName()) << "|"; 
            std::cout << ColumnFormat(contacts[i].GetLastName()) << "|"; 
            std::cout << ColumnFormat(contacts[i].GetNickName()) << "|" << std::endl; 
        }
        i++;
    }
    
    //TO ADD A WHILE (1)
    while (1)
    {
        std::cout << "Enter the index of the contact to view details: ";
        if (!(std::cin >> j)) {
            std::cin.clear(); // Clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input (clear buffer input)
            std::cerr << "Invalid input. Please enter a number." << std::endl;
            continue;
        }
        else
            break;
    }
    if (j >= 0 && j < 8 && !contacts[j].GetFirstName().empty())
    {
        std::cout << "--- Contact details: ---" << std::endl;
        std::cout << "* FirstName: " << contacts[j].GetFirstName() << std::endl;
        std::cout << "* LastName: " << contacts[j].GetLastName() << std::endl;
        std::cout << "* NickName: " << contacts[j].GetNickName() << std::endl;
        std::cout << "* PhoneNumber: " << contacts[j].GetPhoneNumber() << std::endl;
        std::cout << "* DarkestSecret: " << contacts[j].GetDarkestSecret() << std::endl;
    }
    else
        std::cerr << "Empty contact." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
