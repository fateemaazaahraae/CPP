/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:42:54 by fbazaz            #+#    #+#             */
/*   Updated: 2024/10/15 16:17:26 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int main(int ac, char **av)
{
    int i;
    int j;
    
    i = 0;
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (1);
    }
    while (av[++i])
    {
        j = -1;
        while (av[i][++j])
            std::cout << (char)std::toupper(av[i][j]);
    }
    std::cout << "\n";
    return (0);
}