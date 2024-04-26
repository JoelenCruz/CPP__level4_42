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


Cat::Cat(void) : AAnimal("Cat")
{
	if (MSG == true)
		PRINT("🐈 Cat: Default constructor")
	this->_brain = new Brain();
	return ;
}

Cat::Cat(Cat const &src) : AAnimal(src)
{
	if (MSG == true)
		PRINT("🐈 Cat: Copy constructor!")
	this->_name = src.getName();
	this->_brain = new Brain(*src._brain);
	return ;
}


Cat::~Cat(void)
{
	if (MSG == true)
		PRINT("❌🐈 Cat Destructor called");
	delete this->_brain;
	return ;
}

// *=============================================================================
// *OPERATORS
// *=============================================================================



Cat & Cat::operator = (Cat const &rhs)
{
	if (MSG == true)
		PRINT("🐈 Assignment operator called")
	if (this != &rhs)
	{
		_name = rhs.getName();
		delete this->_brain;
		_brain = new Brain(*rhs._brain);
	}
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

std::string	Cat::getIdea(size_t i) const
{
	return(this->_brain->getIdea(i));
}

void	Cat::setIdea(size_t i, std::string &idea)
{
	this->_brain->setIdea(i, idea);
}

Brain	*Cat::getBrain(void) const
{
	return (this->_brain);
}