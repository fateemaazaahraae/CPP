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
    std::string name;
    int i;
    int size;

    std::cout << "Enter the number of Zombies you want: ";
    std::cin >> size;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter the name of the Zombies: ";
    std::getline(std::cin, name);
    HordeOfZombie = zombieHorde(size, name);
    i = 0;
    while (i < size)
    {
        HordeOfZombie[i].announce();
        i++;
    }

    delete[] HordeOfZombie;
}