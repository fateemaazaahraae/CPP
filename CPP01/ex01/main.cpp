/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 09:56:01 by tiima             #+#    #+#             */
/*   Updated: 2024/10/19 10:53:53 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
    Zombie* HordeOfZombie;
    int i;
    int size = 8;

    HordeOfZombie = zombieHorde(size, "Zoooo");
    i = 0;
    while (i < size)
    {
        HordeOfZombie[i].announce();
        i++;
    }

    delete[] HordeOfZombie;
}