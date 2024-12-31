/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 09:19:49 by tiima             #+#    #+#             */
/*   Updated: 2024/12/31 15:27:07 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    int size = 4;
    Animal* animals[size];

    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < size; i++) {
        animals[i]->makeSound();
    }

    for (int i = 0; i < size; i++) {
        delete animals[i];
    }

    std::cout << "\n## DEEP COPY VS SHALLOW COPY ##\n\n";
    
    Cat cat;
    Cat cat1(cat);
    std::cout << cat.getBrainIdea(0) << std::endl;
    std::cout << cat1.getBrainIdea(0) << std::endl;
    cat.setBrainIdea("bb", 0);
    std::cout << cat.getBrainIdea(0) << std::endl;
    std::cout << cat1.getBrainIdea(0) << std::endl;
    return 0;
}
