/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 09:56:10 by tiima             #+#    #+#             */
/*   Updated: 2024/12/05 11:39:48 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie* HordeOfZombies;
    int i;
    
    HordeOfZombies = new Zombie[N];
    i = 0;
    while (i < N)
    {
        HordeOfZombies[i].setName(name);
        i++;
    }
    return (HordeOfZombies);
}