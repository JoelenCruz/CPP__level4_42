/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:08:21 by joe               #+#    #+#             */
/*   Updated: 2024/02/24 15:28:05 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

int	main()
{
	Zombie	*zombies, zombie("Stack");

	zombies = zombieHorde(HORDE_SIZE, "Heap");
	for (int i = 0; i < HORDE_SIZE; i++)
		(zombies + i)->announce();
	zombie.announce();
	std::cout << std::endl;
	delete [] zombies;
	return (0);
}