/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:42:20 by tiima             #+#    #+#             */
/*   Updated: 2024/11/09 10:02:59 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

int main()
{
    Harl Harl1;

    Harl1.complain("debug");
    Harl1.complain("warning");
    Harl1.complain("info");
    Harl1.complain("error");
}