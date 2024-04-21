/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:34:06 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/21 14:57:30 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#define MSG true

// *=============================================================================
// *CONSTRUCTORS AND DESTRUCTOR
// *=============================================================================

ScavTrap::ScavTrap(void) : ClapTrap("Default", 100, 50, 20)
{
	if (MSG == true)
		PRINT("⚫ ScavTrap Default constructor!");
	return ;
}


ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name, 100, 50, 20)
{
	if (MSG == true)
		PRINT("⚫ ScavTrap constructor with name");
	return ;
}


ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	if (MSG == true)
		PRINT("⚫ ScavTrap Copy constructor called");
	return ;
}

ScavTrap::~ScavTrap(void)
{
	if (MSG == true)
		PRINT("❌ ScavTrap Destructor called");
	return ;
}

// *=============================================================================
// *OPERATORS
// *=============================================================================

ScavTrap & ScavTrap::operator = (ScavTrap const &rhs)
{
	if (MSG == true)
	{
		PRINT("⚫ ScavTrap Assignment operator called")
		PRINT(rhs)	
	}
	if (this != &rhs)
		this->ClapTrap::operator = (rhs);
	return *this;
}

// *=============================================================================
// *MEMBER FUNCTIONS
// *=============================================================================


void	ScavTrap::attack(const std::string &target)
{
	if (!getAttacksPoints())
	{
		PRINT("ScavTrap " << getName() << \
			" doesn't have any more energy!");
		return ;
	}
	PRINT("ScavTrap " << getName() << " attacks " << target << \
		", causing " << getDamage() << " points of damage!");
	setAttacksPoints(getAttacksPoints() - 1);
}


void	ScavTrap::guardGate(void)
{
	PRINT("ScavTrap is now in guardGate mode.");
}


std::ostream & operator << (std::ostream &o, ScavTrap const &i)
{
	o << "+---" << std::endl;
	o << "| ScavTrap" << std::endl;
	o << "| Name: " << i.getName() << std::endl;
	o << "| Hit Points: " << i.getHitPoints() << std::endl;
	o << "| Energy Points: " << i.getAttacksPoints() << std::endl;
	o << "| Attack Damage: " << i.getDamage() << std::endl;
	o << "+---" << std::endl;
	return (o);
}