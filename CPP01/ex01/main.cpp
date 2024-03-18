/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:08:21 by joe               #+#    #+#             */
/*   Updated: 2024/03/18 19:59:28 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

int	main()
{
	if (!verifyPositive(HORDE_SIZE))
    {
        std::cout << "HORDE_SIZE:" << HORDE_SIZE << " negative number!" <<"\n";
        return (0);
    }
	
	Zombie	*zombies, zombie("Stack");

	zombies = zombieHorde(HORDE_SIZE, "Heap");
	
	for (int i = 0; i < HORDE_SIZE; i++)
		(zombies + i)->announce();
	
	zombie.announce();
	std::cout << std::endl;
	
	delete [] zombies;
	
	return (0);
}