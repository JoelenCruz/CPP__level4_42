/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:25:49 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/05 19:41:09 by jcruz-da         ###   ########.fr       */
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

/**
 * @brief Constrói um novo objeto Fixed.
 * 
 * @param value O valor _nbInt.
 */
Fixed::Fixed(const int value) : _nbInt(value << _nbFractional)
{
	PRINT("Int constructor called");
	return ;
}

/**
 * @brief Construct a new Fixed:: Fixed object
 * 
 * @param value The _nbInt value.
 */
// Since 'value' is float can't bitshift it directly, so 'roundf' must be used.
Fixed::Fixed(const float value) : _nbInt(roundf(value * (1 << _nbFractional)))
{
	PRINT("Float constructor called");
	return ;
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

/**
 * @brief Gets the value in _nbInt
 * 
 * @return int _nbInt
 */
int	Fixed::getRawBits(void) const
{
	return (this->_nbInt);
}

// *=============================================================================
// *SETTERS
// *=============================================================================

/**
 * @brief Sets a new value to _nbInt
 * 
 * @param raw The new value to _nbInt.
 */
void	Fixed::setRawBits(int const raw)
{
	this->_nbInt = raw;
	return ;
}



// *=============================================================================
// *FUNCTIONS
// *=============================================================================

float	Fixed::toFloat(void) const
{
	return ((float)getRawBits() / (1 << _nbFractional));
}

/**
 * @brief Converts the object raw value to int
 * 
 * @return int The converted value.
 */
int	Fixed::toInt(void) const
{
	return (getRawBits() >> _nbFractional);
}

/**
 * @brief Overload for the 'std::onstream <<' operator.
 * 
 * @param o Output stream
 * @param i Input stream
 * @return std::ostream& Reference to the output.
 */
std::ostream & operator << (std::ostream & o, Fixed const & i)
{
	// Checks if 'i' is zero.
	if (i.getRawBits() & 0xFF)
		o << i.toFloat();
	else
		o << i.toInt();
	return (o);
}