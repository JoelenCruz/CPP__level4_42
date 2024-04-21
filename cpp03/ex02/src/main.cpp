/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:29:41 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/21 14:00:59 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	PRINT("\nCalling Constructors");
	ClapTrap	clap;
	ScavTrap	scav;
	FragTrap	frag;
	FragTrap	frag1("Xmen");
	FragTrap	frag2("Justice League");
	FragTrap	frag3 = frag;
	FragTrap	frag4 = frag3 = frag;

	PRINT("\nShow Traps' Status");
	PRINT(clap);
	PRINT(scav);
	PRINT(frag1);
	PRINT(frag2);

	PRINT("High Five Time");
	frag2.highFivesGuy();

	PRINT("\nCalling Destructors");
	return (0);
}