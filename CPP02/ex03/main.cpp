/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:30:29 by tiima             #+#    #+#             */
/*   Updated: 2024/11/23 16:21:21 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

int main( void )
{
    Point a(0, 0);
    Point b(4, 0);
    Point c(0, 3);

    Point p(2, 0);
    if (bsp(a, b, c, p) == true)
        std::cout << "The point INSIDE the triagle\n";
    else
        std::cout << "The point OUTSIDE the triagle\n";
    return 0;
}

