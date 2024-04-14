/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:29:41 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/14 20:30:37 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	PRINT("\nCalling Constructors");
	ClapTrap	trap;
	ScavTrap	scav;
	ScavTrap	scav1("Marvin");
	ScavTrap	scav2("Wall-E");
	ScavTrap	scav3 = scav;
	ScavTrap	scav4 = scav3 = scav;

	PRINT("\nShow Traps' Status");
	PRINT(trap);
	PRINT(scav1);
	PRINT(scav2);

	PRINT("ScavTraps Showing Off");
	for (int i = 0; i < 3; i++)
	{
		scav1.attack("Wall-E");
		scav2.takeDamage(scav1.getDamage());
	}

	PRINT("\nShow ScavTraps' Status");
	PRINT(scav1);
	PRINT(scav2);

	PRINT("Guard Stance");
	scav2.guardGate();

	PRINT("\nRepairing Time");
	for (int i = 0; i < 3; i++)
		scav2.beRepaired(20);

	PRINT("\nShow ClapTraps' Status");
	PRINT(scav1);
	PRINT(scav2);

	PRINT("Calling Destructors");
	return (0);
}