/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:11:06 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/03/30 17:14:10 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include "Fixed.hpp"

#define SHOW_MSG false

// =============================================================================
// CONSTRUCTOR & DESTRUCTOR
// =============================================================================

/**
 * @brief Construct a new Fixed:: Fixed object
 * 
 */
Fixed::Fixed(void) : _raw(0)
{
	if (SHOW_MSG == true)
		LOG("Default constructor called");
	return ;
}

/**
 * @brief Construct a new Fixed:: Fixed object
 * 
 * @param value The _raw value.
 */
Fixed::Fixed(const int value) : _raw(value << _fractionBits)
{
	if (SHOW_MSG == true)
		LOG("Int constructor called");
	return ;
}

/**
 * @brief Construct a new Fixed:: Fixed object
 * 
 * @param value The _raw value.
 */
// Since 'value' is float can't bitshift it directly, so 'roundf' must be used.
Fixed::Fixed(const float value) : _raw(roundf(value * (1 << _fractionBits)))
{
	if (SHOW_MSG == true)
		LOG("Float constructor called");
	return ;
}

/**
 * @brief Construct a new Fixed:: Fixed object
 * 
 * @param src The fixed object to be copied.
 */
Fixed::Fixed(Fixed const &src)
{
	if (SHOW_MSG == true)
		LOG("Copy constructor called");
	*this = src;
	return ;
}

/**
 * @brief Destroy the Fixed:: Fixed object
 * 
 */
Fixed::~Fixed(void)
{
	if (SHOW_MSG == true)
		LOG("Destructor called");
	return ;
}

// =============================================================================
// OPERATORS
// =============================================================================

/**
 * @brief Overload for the '=' operator.
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return Fixed& A pointer to the assigned Fixed object.
 */
Fixed & Fixed::operator= (Fixed const &rhs)
{
	if (SHOW_MSG == true)
		LOG("Copy assignment operator called")
	if (this != &rhs)
		_raw = rhs.getRawBits();
	return *this;
}

// =============================================================================
// LOGIC OPERATORS OVERLOAD
// =============================================================================

/**
 * @brief Overload for the '>' operator.
 * 
 * @param rhs The right hand side variable to be compared with.
 * @return true When the object is greater than the 'rhs' object.
 * @return false When the object isn't greater than the 'rhs' object.
 */
bool	Fixed::operator > (const Fixed &rhs) const
{
	return (getRawBits() > rhs.getRawBits());
}

/**
 * @brief Overload for the '<' operator.
 * 
 * @param rhs The right hand side variable to be compared with.
 * @return true When the object is lesser than the 'rhs' object.
 * @return false When the object isn't lesser than the 'rhs' object.
 */
bool	Fixed::operator < (const Fixed &rhs) const
{
	return (getRawBits() < rhs.getRawBits());
}

/**
 * @brief Overload for the '>=' operator.
 * 
 * @param rhs The right hand side variable to be compared with.
 * @return true When the object is greater than or equal to the 'rhs' object.
 * @return false When the object isn't greater than or equal to the 'rhs' object.
 */
bool	Fixed::operator >= (const Fixed &rhs) const
{
	return (getRawBits() >= rhs.getRawBits());
}

/**
 * @brief Overload for the '<=' operator.
 * 
 * @param rhs The right hand side variable to be compared with.
 * @return true When the object is lesser than or equal to the 'rhs' object.
 * @return false When the object isn't lesser than or equal to the 'rhs' object.
 */
bool	Fixed::operator <= (const Fixed &rhs) const
{
	return (getRawBits() <= rhs.getRawBits());
}

/**
 * @brief Overload for the '==' operator.
 * 
 * @param rhs The right hand side variable to be compared with.
 * @return true When the object equal to the 'rhs' object.
 * @return false When the object isn't equal to the 'rhs' object.
 */
bool	Fixed::operator == (const Fixed &rhs) const
{
	return (getRawBits() == rhs.getRawBits());
}

/**
 * @brief Overload for the '!=' operator.
 * 
 * @param rhs The right hand side variable to be compared with.
 * @return true When the object isn't equal to the 'rhs' object.
 * @return false When the object is equal to the 'rhs' object.
 */
bool	Fixed::operator != (const Fixed &rhs) const
{
	return (getRawBits() != rhs.getRawBits());
}

// =============================================================================
// ARITHMETIC OPERTATORS OVERLOAD
// =============================================================================

/**
 * @brief Overload for the '+' operator.
 * 
 * @param rhs The right hand side variable to be summed from.
 * @return Fixed The sum's result.
 */
Fixed	Fixed::operator + (const Fixed &rhs) const
{
	Fixed	i;
	
	i.setRawBits(getRawBits() + rhs.getRawBits());
	return (i);
}

/**
 * @brief Overload for the '-' operator.
 * 
 * @param rhs The right hand side variable to be subtracted from.
 * @return Fixed The subtract's result.
 */
Fixed	Fixed::operator - (const Fixed &rhs) const
{
	Fixed	i;

	i.setRawBits(getRawBits() - rhs.getRawBits());
	return (i);
}

/**
 * @brief Overload for the '-' operator.
 * 
 * @param rhs The right hand side variable to be multiplied from.
 * @return Fixed The multiplys result.
 */
Fixed	Fixed::operator * (const Fixed &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

/**
 * @brief Overload for the '-' operator.
 * 
 * @param rhs The right hand side variable to be divided from.
 * @return Fixed The division's result.
 */
Fixed	Fixed::operator / (const Fixed &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

// =============================================================================
// INCREMENTE AND DECREMENT OPERATORS OVERLOAD
// =============================================================================

/**
 * @brief Overload for the '++' operator.
 * 
 * @return Fixed& A pointer to the object after '_raw' is incremented.
 */
Fixed	&Fixed::operator ++ (void)
{
	++this->_raw;
	return (*this);
}

/**
 * @brief Overload for the '++' operator.
 * 
 * @return Fixed The incremented value.
 */
Fixed	Fixed::operator ++ (int)
{
	Fixed	i = *this;
	
	this->_raw++;
	return (i);
}

/**
 * @brief Overload for the '--' operator.
 * 
 * @return Fixed& A pointer to the object after '_raw' is decremented.
 */
Fixed	&Fixed::operator -- (void)
{
	--this->_raw;
	return (*this);
}

/**
 * @brief Overload for the '--' operator.
 * 
 * @return Fixed The decremented value.
 */
Fixed	Fixed::operator -- (int)
{
	Fixed	i = *this;
	
	this->_raw--;
	return (i);
}

// =============================================================================
// MIN AND MAX OPERATORS OVERLOAD
// =============================================================================

/**
 * @brief Overload for the 'min' operator
 * 
 * @param lhs The equation's left hand side.
 * @param rhs The equation's right hand side.
 * @return Fixed& Pointer to the smallest  object.
 */
Fixed	&Fixed::min(Fixed &lhs, Fixed &rhs)
{
	return (lhs > rhs ? rhs : lhs);
}

/**
 * @brief Overload for the 'min' operator
 * 
 * @param lhs The equation's left hand side.
 * @param rhs The equation's right hand side.
 * @return Fixed& Pointer to the smallest  object.
 */
Fixed	&Fixed::min(Fixed const &lhs, Fixed const &rhs)
{
	return (Fixed::min((Fixed &)lhs, (Fixed &)rhs));
}

/**
 * @brief Overload for the 'max' operator
 * 
 * @param lhs The equation's left hand side.
 * @param rhs The equation's right hand side.
 * @return Fixed& Pointer to the bigger  object.
 */
Fixed	&Fixed::max(Fixed &lhs, Fixed &rhs)
{
	return (lhs < rhs ? rhs : lhs);
}

/**
 * @brief Overload for the 'max' operator
 * 
 * @param lhs The equation's left hand side.
 * @param rhs The equation's right hand side.
 * @return Fixed& Pointer to the bigger  object.
 */
Fixed	&Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
	return (Fixed::max((Fixed &)lhs, (Fixed &)rhs));
}

// =============================================================================
// GETTERS
// =============================================================================

/**
 * @brief Gets the value in _raw
 * 
 * @return int _raw
 */
int	Fixed::getRawBits(void) const
{
	return (this->_raw);
}

// =============================================================================
// SETTERS
// =============================================================================

/**
 * @brief Sets a new value to _raw
 * 
 * @param raw The new value to _raw.
 */
void	Fixed::setRawBits(int const raw)
{
	this->_raw = raw;
	return ;
}

// =============================================================================
// FUNCTIONS
// =============================================================================

/**
 * @brief Converts rawBits into float.
 * 
 * @return float rawBits converted as float.
 */
float	Fixed::toFloat(void) const
{
	return ((float)getRawBits() / (1 << _fractionBits));
}

/**
 * @brief Convertes rawBits into int.
 * 
 * @return int rawBits converted as int.
 */
int	Fixed::toInt(void) const
{
	return (getRawBits() >> _fractionBits);
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