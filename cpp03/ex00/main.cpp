/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:55:46 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/21 14:39:15 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
    PRINT("\n---------Constructors-----------------");
	ClapTrap	trap;
	ClapTrap	trap1("X-men");
	ClapTrap	trap2("Justice League");
	ClapTrap	trap3 = trap;
	ClapTrap	trap4 = trap3 = trap1;

    PRINT("\n-------------ClapTraps' Status-----------");
    PRINT(trap1);
    PRINT(trap2);

    PRINT("-----Update Xmen's Attack Damage------");
	trap1.setDamage(1);
    PRINT(trap1);

    PRINT("------------ClapTraps Showing Off--------");
	for (int i = 0; i < 11; i++)
	{
		trap1.attack("Justice League");
		trap2.takeDamage(trap1.getDamage());
        PRINT("\n");
	}

    PRINT("\n------------Show ClapTraps' Status-----------");
    PRINT(trap1);
    PRINT(trap2);

    PRINT("Repairing Time");
	for (int i = 0; i < 3; i++)
		trap2.beRepaired(1);

    PRINT("\nShow ClapTraps' Status");
    PRINT(trap1);
    PRINT(trap2);

    PRINT("Calling Destructors");
	return (0);
}