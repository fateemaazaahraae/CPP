/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:27:54 by tiima             #+#    #+#             */
/*   Updated: 2024/12/03 14:31:34 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"

Brain::Brain() {
    std::cout << "The Brain Constructor called" << std::endl;
}

Brain::~Brain() {
    std::cout << "The Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "The Brain Copy Constructor called" << std::endl;
    *this = other;
}

Brain&  Brain::operator=(const Brain& other) {
    std::cout << "The Brain Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}
