/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:50:56 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/21 14:56:34 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#define MSG true

// *=============================================================================
// *CONSTRUCTORS AND DESTRUCTOR
// *=============================================================================


FragTrap::FragTrap(void) : ClapTrap("Default", 100, 100, 30)
{
	if (MSG == true)
		PRINT("🪤 FragTrap Default constructor!");
	return ;
}


FragTrap::FragTrap(std::string const &name) : ClapTrap(name, 100, 100, 30)
{
	if (MSG == true)
		PRINT("🪤 FragTrap constructor whit name!");
	return ;
}


FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	if (MSG == true)
		PRINT("🪤 FragTrap Copy construtor!");
	return ;
	
}


FragTrap::~FragTrap(void)
{
	if (MSG == true)
		PRINT("❌ FragTrap destructor!");
	return ;
}

// *=============================================================================
// *OPERATORS
// *=============================================================================


FragTrap & FragTrap::operator = (FragTrap const &rhs)
{
	if (MSG == true)
		PRINT("🪤 FragTrap Assignment operator!");
	if (this != &rhs)
		this->ClapTrap::operator = (rhs);
	return (*this);
}

// *=============================================================================
// *MEMBER FUNCTIONS
// *=============================================================================

/**
 * @brief The FragTrap prints a message asking for a high five
 * 
 */
void	FragTrap::highFivesGuy(void)
{
	PRINT("FragTrap requests a high five!");
}

/**
 * @brief Overload for the 'std::onstream <<' operator.
 * 
 * @param o Output stream
 * @param i Input stream
 * @return std::ostream& Reference to the output.
 */
std::ostream & operator << (std::ostream  &o, FragTrap const &i)
{
	o << "+---" << std::endl;
	o << "| FragTrap" << std::endl;
	o << "| Name: " << i.getName() << std::endl;
	o << "| Hit Points: " << i.getHitPoints() << std::endl;
	o << "| Energy Points: " << i.getAttacksPoints() << std::endl;
	o << "| Attack Damage: " << i.getDamage() << std::endl;
	o << "+---" << std::endl;
	return (o);
}