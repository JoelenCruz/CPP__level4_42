/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:08:27 by joe               #+#    #+#             */
/*   Updated: 2024/02/24 15:26:42 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

bool verifyPositive(int number) 
{
    // Verifica se o número é maior que zero
    if (number > 0) {
        return true; // Retorna verdadeiro se for positivo
    } else {
        return false; // Retorna falso se não for positivo
    }
}

Zombie *zombieHorde(int X, std::string name)
{
    if (!verifyPositive(X)){
        return (NULL);
    }
    else{        
    Zombie *zombies = new Zombie[X];
    for (int i = 0; i < X; i++)
    {
        zombies[i].setName(name);
    }
    return (zombies);
    }
}