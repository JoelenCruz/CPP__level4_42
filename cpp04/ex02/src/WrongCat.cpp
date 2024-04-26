/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:11:34 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/21 17:19:47 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"

#define MSG true

// *=============================================================================
// *CONSTRUCTORS AND DESTRUCTOR
// *=============================================================================


WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	if (MSG == true)
		PRINT("❌🐈 WrongCat: Default constructor!");
	return ;
}


WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
	if (MSG == true)
		PRINT("❌🐈 WrongCat: Copy constructor with name");
	this->_name = src.getName();
	return ;
}


WrongCat::~WrongCat(void)
{
	if (MSG == true)
		PRINT("❌🐈 WrongCat Destructor called");
	return ;
}

// *=============================================================================
// *OPERATORS OVERLOAD
// *=============================================================================


WrongCat & WrongCat::operator = (WrongCat const &rhs)
{
	if (MSG == true)
		PRINT("❌🐈 WrongCat: Assignment operator!");
	if (this != &rhs)
		_name = rhs.getName();
	return (*this);
}

// *=============================================================================
// *MEMBER FUNCTIONS
// *=============================================================================


void	WrongCat::makeSound(void) const
{
	PRINT("Not a Miau!");
}