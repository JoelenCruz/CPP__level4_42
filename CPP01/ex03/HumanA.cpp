/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:33:24 by joe               #+#    #+#             */
/*   Updated: 2024/02/26 19:33:58 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	return ;
}

HumanA::~HumanA(void)
{
	return ;
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

void	HumanA::attack(void)
{
	std::cout << _name << " attacks with their ";
	std::cout << _weapon.getType() << std::endl;
}