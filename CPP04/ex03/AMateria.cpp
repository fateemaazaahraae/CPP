/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:26:40 by fbazaz            #+#    #+#             */
/*   Updated: 2024/12/31 18:02:55 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"

AMateria::AMateria() : _type("Default") {}

AMateria::AMateria(std::string const& type) : _type(type) {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria& other) {
    *this = other;
}

AMateria& AMateria::operator=(const AMateria& other) {
    (void)other;
    return *this;
}

std::string const&  AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter& target) { (void)target; }