/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:35:36 by joe               #+#    #+#             */
/*   Updated: 2024/02/26 19:35:58 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"


Weapon::Weapon(std::string type) : _type(type)
{
	return ;
}


Weapon::~Weapon(void)
{
	return ;
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================


std::string const	&Weapon::getType(void) const
{
	return _type;
}


void	Weapon::setType(std::string new_type)
{
	_type = new_type;
}