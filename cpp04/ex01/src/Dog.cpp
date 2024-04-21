/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:43:21 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/21 17:27:31 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#define MSG true

// *=============================================================================
// *CONSTRUCTORS AND DESTRUCTOR
// *=============================================================================


Dog::Dog(void) : Animal("Dog")
{
	if (MSG == true)
		PRINT("🐕 Dog: Default constructor")
	return ;
}

Dog::Dog(Dog const &src) : Animal(src)
{
	if (MSG == true)
		PRINT("🐕 Dog: Copy constructor!")
	this->_name = src.getName();
	return ;
}


Dog::~Dog(void)
{
	if (MSG == true)
		PRINT("❌🐕 Dog: Destructor called")
}

// *=============================================================================
// *OPERATORS
// *=============================================================================



Dog & Dog::operator = (Dog const &rhs)
{
	if (MSG == true)
		PRINT("🐕 Assignment operator!")
	if (this != &rhs)
		_name = rhs.getName();
	return (*this);
}

std::ostream &operator << (std::ostream &o, Dog const &i)
{
	(void)i;
	o << "Dog";
	return (o);
}

// *=============================================================================
// *MEMBER FUNCTIONS
// *=============================================================================


void	Dog::makeSound(void) const
{
    PRINT("Au! Au! Au! Au!")
}



std::string	Dog::getIdea(size_t i) const
{
	return(this->_brain->getIdea(i));
}


void	Dog::setIdea(size_t i, std::string &idea)
{
	this->_brain->setIdea(i, idea);
}

Brain	*Dog::getBrain(void) const
{
	return (this->_brain);
}