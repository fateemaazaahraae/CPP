/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 09:19:49 by tiima             #+#    #+#             */
/*   Updated: 2024/12/03 11:28:20 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    std::cout << std::endl << "---------- THE WRONG ANIMAL TEST ----------" << std::endl << std::endl;
    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* cat = new WrongCat();
    std::cout << cat->getType() << std::endl;
    wrong->makeSound();
    cat->makeSound();
    return 0;
}