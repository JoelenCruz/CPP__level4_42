/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:56:29 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/21 17:20:56 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#define MSG true

// *=============================================================================
// *CONSTRUCTORS AND DESTRUCTOR
// *=============================================================================


WrongAnimal::WrongAnimal(void) : _name("WrongUndefined")
{
	if (MSG == true)
	    PRINT("❌🧬 WrongAnimal: Default constructor!");
	return ;
}


WrongAnimal::WrongAnimal(std::string const &name) : _name(name)
{
	if (MSG == true)
	    PRINT("❌🧬 WrongAnimal: Constructor with name!");
	return ;
}


WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	if (MSG == true)
	    PRINT("❌🧬 WrongAnimal: Copy constructor!");
	this->_name = src.getName();
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	if (MSG == true)
	    PRINT("❌🧬 WrongAnimal: Destructor called");
	return ;
}

// *=============================================================================
// *OPERATOR
// *=============================================================================


WrongAnimal & WrongAnimal::operator = (WrongAnimal const &rhs)
{
	if (MSG == true)
	    PRINT("❌🧬 WrongAnimal: Assignment operator");
	if (this != &rhs)
		_name = rhs._name;
	return (*this);
}

// *=============================================================================
// *MEMBER FUNCTIONS
// *=============================================================================


std::string	WrongAnimal::getName(void) const
{
	return (_name);
}


void	WrongAnimal::makeSound(void) const
{
    PRINT("Not Bazinga");
}