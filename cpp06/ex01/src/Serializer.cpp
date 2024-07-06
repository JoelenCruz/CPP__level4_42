/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:20:53 by joe               #+#    #+#             */
/*   Updated: 2024/06/29 15:04:28 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

// =============================================================================
// Constructor and Destructors
// =============================================================================


Serializer::Serializer(void)
{
	PRINT_COLOR(BLUE, "▶️ Default constructor called.");
}

Serializer::Serializer(Serializer const &src)
{
	PRINT_COLOR(BLUE,"▶️ Copy constructor called.");
	(void)src;
}

Serializer::~Serializer(void)
{
	PRINT_COLOR(BLUE,"▶️ Destructor called.");
}

// =============================================================================
// Operator Overload
// =============================================================================


Serializer & Serializer::operator = (Serializer const &rhs)
{
	PRINT_COLOR(BLUE,"▶️ Assignment operator called.");
	(void)rhs;
	return (*this);
}

// =============================================================================
// Functions
// =============================================================================

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}


Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}