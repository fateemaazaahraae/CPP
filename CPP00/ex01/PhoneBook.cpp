/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:55:11 by fbazaz            #+#    #+#             */
/*   Updated: 2024/10/14 15:09:58 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

void    PhoneBook::AddContact(Contact& element) {
    if (GetIndex() == 8)
        SetIndex(0);
    contacts[GetIndex()] = element;
    SetIndex(GetIndex() + 1);
}

void    PhoneBook::SearchContact() {}

