/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:42:47 by fbazaz            #+#    #+#             */
/*   Updated: 2024/10/15 15:20:01 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

//   Getters
std::string Contact::GetFirstName() const {
    return (FirstName);
}

std::string Contact::GetLastName() const {
    return (LastName);
}

std::string Contact::GetNickName() const {
    return (NickName);
}

std::string Contact::GetPhoneNumber() const {
    return (PhoneNumber);
}

std::string Contact::GetDarkestSecret() const {
    return (DarkestSecret);
}

//  Setters
void    Contact::SetFirstName(std::string& First)
{
    FirstName = First;
}

void    Contact::SetLastName(std::string& Last)
{
    LastName = Last;
}

void    Contact::SetNickName(std::string& Nick)
{
    NickName = Nick;
}

void    Contact::SetPhoneNumber(std::string& Number)
{
    PhoneNumber = Number;
}

void    Contact::SetDarkestSecret(std::string& Dark)
{
    DarkestSecret = Dark;
}