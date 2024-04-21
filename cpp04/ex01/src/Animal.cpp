/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:07:20 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/21 16:40:14 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// *==============================================================================
// *CONSTURCTOR AND DESTRUCTOR  
// *==============================================================================

#define MSG true

Animal::Animal(void)
{
    PRINT("🧬 Animal Default constructor!");
    return;
}

Animal::Animal(std::string const &name) : _name(name)
{
	if (MSG == true)
    {
		PRINT("🧬 String constructor with name");
        PRINT(name);
    }
	return ;
}

Animal::Animal(Animal const &src)
{
    if (MSG == true)
        PRINT("🧬 Animal Copy constructor!");
    this->_name = src.getName();
	return ;
}

Animal::~Animal(void)
{
    PRINT("Animal Destructor called");
    return;
}

// *=============================================================================
// *OPERATOR
// *=============================================================================

Animal & Animal::operator = (Animal const &rhs)
{
	if (MSG == true)
		PRINT("🧬 Assignment operator called");
	if (this != &rhs)
		_name = rhs._name;
	return (*this);
}

std::ostream &operator << (std::ostream &o, Animal const &i)
{
	(void)i;
	o << "Animal";
	return (o);
}

// *=============================================================================
// *MEMBER FUNCTIONS
// *=============================================================================


std::string	Animal::getName(void) const
{
	return (_name);
}

void	Animal::makeSound(void) const
{
	PRINT("bazinga!!!!!");
}
