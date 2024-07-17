/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:59:06 by joe               #+#    #+#             */
/*   Updated: 2024/07/17 00:28:08 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int main(int argc, char* argv[]) 
{
    if (argc < 2) 
    {
        std::cerr << "Uso: " << argv[0] << " number1 number2 ... numeroN" << std::endl;
        return 1;
    }

    PmergeMe pmerge(argc, argv);

    return 0;
}