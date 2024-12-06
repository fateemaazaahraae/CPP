/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:52:08 by tiima             #+#    #+#             */
/*   Updated: 2024/12/05 11:54:53 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>

void    replaceStrings(std::ofstream& file, std::string s1, std::string s2, std::string input)
{
    std::string modifiedLine;
    size_t      i;

    i = 0;
    while (input[i])
    {
        if (input.substr(i, s1.length()) == s1)
        {
            modifiedLine += s2;
            i += s1.length();
        }
        else
        {
            modifiedLine += input[i];
            i++;
        }
    }
    file << modifiedLine;
}

int main(int ac, char **av)
{
    std::string     s1;
    std::string     s2;
    std::string     str;
    std::string     file;
    std::string     fileReplace;
    std::ifstream   inFile;
    std::ofstream   outFile;
    bool            firstLine;

    if (ac != 4)
    {
        std::cout << "Invalid number of args !." << std::endl;
        return (1);
    }
    file = av[1];
    s1 = av[2];
    s2 = av[3];
    fileReplace = file + ".replace";
    if (s1.empty() || s2.empty())
    {
        std::cout << "Strings should be non empty !." << std::endl;
        return (1);
    }
    inFile.open(file.c_str());
    if (!inFile.is_open())
    {
        std::cout << "Error: Could not open input file !." << std::endl;
        return (1);
    }
    outFile.open(fileReplace.c_str());
    if (!outFile.is_open())
    {
        inFile.close();
        std::cout << "Error: Could not create output file !." << std::endl;
        return (1);
    }
    firstLine = true;
    while (std::getline(inFile, str))
    {
        if (!firstLine)
            outFile << std::endl;
        replaceStrings(outFile, s1, s2, str);
        firstLine = false;
    }
    inFile.close();
    outFile.close();
}