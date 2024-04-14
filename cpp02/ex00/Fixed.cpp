/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:13:24 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/09 18:09:10 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// *==============================================================================
// *CONSTURCTOR AND DESTRUCTOR  
// *==============================================================================

Fixed::Fixed(void): _nbInt(0)
{
    PRINT("Default constructor called");
    return;
}

Fixed::Fixed(Fixed const &src)
{
    PRINT("Copy constructor called");
    *this=src;
    return;
}

Fixed::~Fixed(void)
{
    PRINT("Destructor called");
    return;
}

// *==============================================================================
// *OPERATOR 
// *==============================================================================

Fixed & Fixed::operator= (Fixed const &rhs)
{
    PRINT("Copy assignment operator called");
    if (this != &rhs)
        _nbInt = rhs.getRawBits();
    return *this;
}

// *=============================================================================
// *GETTERS
// *=============================================================================

int	Fixed::getRawBits(void) const
{
	PRINT("getRawBits member function called")
	return (this->_nbInt);
}

// *=============================================================================
// *SETTERS
// *=============================================================================

void	Fixed::setRawBits(int const raw)
{
	this->_nbInt = raw;
	return ;
}

