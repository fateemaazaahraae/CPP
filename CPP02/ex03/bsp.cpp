/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:37:05 by tiima             #+#    #+#             */
/*   Updated: 2024/11/23 16:17:36 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

const Fixed epsilon = Fixed(1);

Fixed   areaCalculator(Point const x, Point const y, Point const z)
{
    Fixed x1 = x.getX();
    Fixed y1 = x.getY();

    Fixed x2 = y.getX();
    Fixed y2 = y.getY();

    Fixed x3 = z.getX();
    Fixed y3 = z.getY();
    
    Fixed tmp;
    tmp = (x1 * (y2 - y3)) + (x2 * (y3 - y1)) + ( x3 * (y1 - y2));

    if (tmp < Fixed(0))
        tmp = tmp * Fixed(-1);
    return (tmp / Fixed(2));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    // triagle ABC
    Fixed bigTriangle = areaCalculator(a, b, c);
    
    // triagles abp bcp acp
    Fixed abp = areaCalculator(a, b, point);
    Fixed bcp = areaCalculator(b, c, point);
    Fixed acp = areaCalculator(a, c, point);
    if (bigTriangle == (abp + bcp + acp) &&
        abp != Fixed(0) && bcp != Fixed(0) && acp != Fixed(0))
        return (true);
    return (false);
}