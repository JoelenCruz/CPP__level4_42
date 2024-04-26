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

#include "AAnimal.hpp"

// *==============================================================================
// *CONSTURCTOR AND DESTRUCTOR  
// *==============================================================================

#define MSG true

AAnimal::AAnimal(void)
{
    PRINT("🧬 Animal Default constructor!");
    return;
}

AAnimal::AAnimal(std::string const &name) : _name(name)
{
	if (MSG == true)
    {
		PRINT("🧬 String constructor with name");
        PRINT(name);
    }
	return ;
}

AAnimal::AAnimal(AAnimal const &src)
{
    if (MSG == true)
        PRINT("🧬 Animal Copy constructor!");
    this->_name = src.getName();
	return ;
}

AAnimal::~AAnimal(void)
{
    PRINT("Animal Destructor called");
    return;
}

// *=============================================================================
// *OPERATOR
// *=============================================================================

AAnimal & AAnimal::operator = (AAnimal const &rhs)
{
	if (MSG == true)
		PRINT("🧬 Assignment operator called");
	if (this != &rhs)
		_name = rhs._name;
	return (*this);
}

std::ostream &operator << (std::ostream &o, AAnimal const &i)
{
	(void)i;
	o << "Animal";
	return (o);
}

// *=============================================================================
// *MEMBER FUNCTIONS
// *=============================================================================


std::string	AAnimal::getName(void) const
{
	return (_name);
}

void	AAnimal::makeSound(void) const
{
	PRINT("bazinga!!!!!");
}
