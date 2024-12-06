/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 09:19:49 by tiima             #+#    #+#             */
/*   Updated: 2024/12/04 14:50:37 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"

int main()
{
    int size = 10;
    Animal* animal[size];

    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
            animal[i] = new Dog();
        else
            animal[i] = new Cat();
    }

    for (int i = 0; i < size; i++)
        animal[i]->makeSound();

    for (int i = 0; i < size; i++)
        delete animal[i];
}