/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:40:48 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/21 17:27:02 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#define MSG true

// *=============================================================================
// *CONSTRUCTORS AND DESTRUCTOR
// *=============================================================================


Cat::Cat(void) : Animal("Cat")
{
	if (MSG == true)
		PRINT("🐈 Cat: Default constructor")
	return ;
}

Cat::Cat(Cat const &src) : Animal(src)
{
	if (MSG == true)
		PRINT("🐈 Cat: Copy constructor!")
	this->_name = src.getName();
	return ;
}


Cat::~Cat(void)
{
	if (MSG == true)
		PRINT("❌🐈 Cat Destructor called")
}

// *=============================================================================
// *OPERATORS
// *=============================================================================



Cat & Cat::operator = (Cat const &rhs)
{
	if (MSG == true)
		PRINT("🐈 Assignment operator called")
	if (this != &rhs)
		_name = rhs.getName();
	return (*this);
}

std::ostream &operator << (std::ostream &o, Cat const &i)
{
	(void)i;
	o << "Cat";
	return (o);
}

// *=============================================================================
// *MEMBER FUNCTIONS
// *=============================================================================


void	Cat::makeSound(void) const
{
    PRINT("Miau! Miau! Miau Miau")
}