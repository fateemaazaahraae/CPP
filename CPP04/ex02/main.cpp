/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 09:19:49 by tiima             #+#    #+#             */
/*   Updated: 2024/12/31 15:42:54 by fbazaz           ###   ########.fr       */
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
    // const Animal* meta = new Animal(); // This will now cause a compilation error
    const Animal* dog = new Dog(); // This works because Dog is an Animal.
    const Animal* cat = new Cat();

    std::cout << dog->getType() << " says: ";
    dog->makeSound();

    std::cout << cat->getType() << " says: ";
    cat->makeSound();

    delete dog;
    delete cat;

}
