/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:56:04 by joe               #+#    #+#             */
/*   Updated: 2024/03/29 17:18:19 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include "replace.hpp"
//TODO: add a check for empty string(ok)
//TODO: organaize the code into functions and classes
//TODO: o que fazer sobre as strings vazias?
//TODO: o que quando o codigo nao encontra a string pra substituir?


int main(int argc, char *argv[]) 
{
    if (argc != 4) 
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (search_empty(s1) || search_empty(s2))
        return 1;
    else
        replaceInFile(filename, s1, s2);

    return 0;
}



