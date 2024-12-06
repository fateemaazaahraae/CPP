/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:42:46 by tiima             #+#    #+#             */
/*   Updated: 2024/12/05 11:37:25 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

int main()
{
    Zombie *heapZombie = newZombie("HeapZombie");
    heapZombie->announce();

    randomChump("StackZombie");
    delete heapZombie;
}