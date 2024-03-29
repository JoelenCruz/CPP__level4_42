/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:40:07 by joe               #+#    #+#             */
/*   Updated: 2024/02/02 14:26:17 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char *upper_str(char *str){
    int i = 0;
    
    while (str[i]){
        str[i] = toupper(str[i]);
        i++;
    }
    return str;
}


int main(int argc, char **argv)
{
    int x = 0;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else 
    {
        while (++x < argc)
        {
            std::cout << upper_str(argv[x]);
        }
        std::cout << "\n";
    }
    return (0);
}
