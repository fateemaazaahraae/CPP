/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:27:54 by tiima             #+#    #+#             */
/*   Updated: 2025/01/01 09:24:29 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"

Brain::Brain() {
    for (int i = 0; i < 100; i++)
        ideas[i] = "braaain";
    std::cout << "The Brain Constructor called" << std::endl;
}

Brain::~Brain() {
    std::cout << "The Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "The Brain Copy Constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}

Brain&  Brain::operator=(const Brain& other){
    std::cout << "The Brain Copy assignment operator called" << std::endl;
    if (this != &other)
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    return *this;
}

void    Brain::setIdea(std::string idea, int index) {
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

std::string    Brain::getIdea(int index) {
    if (index >= 0 && index < 100)
        return ideas[index];
    return "";
}
