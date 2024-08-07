/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:59:23 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/07/14 15:10:16 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/BitcoinExchange.hpp"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        PRINT_COLOR(RED, "Error: could not open file.");
        PRINT_COLOR(GREEN, "Usage: ./btc input.txt");
        return 1;
    }
    else
    {
        BitcoinExchange btc;
        btc.checkHead(argv[1]);
        btc.superCompare(argv[1]);
            
    }
    return 0;
}
