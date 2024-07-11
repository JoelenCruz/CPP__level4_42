/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:04:41 by joe               #+#    #+#             */
/*   Updated: 2024/07/07 20:49:05 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>


#define RESET_COLOR "\033[0m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define PINK "\033[35m"

#define PRINT_COLOR(color, message) std::cout << color << message << RESET_COLOR << std::endl;


// =============================================================================
// Template
// =============================================================================

template<typename T>

void iter(T* array, size_t size, void (func)(T& value))
{
	if (!array)
		return ;
	for (size_t i = 0; i < size; i++)
		func(array[i]);
}

template<typename T>
void iter(const T* array, size_t size, void (func)(const T& value))
{
	if (!array)
		return ;
	for (size_t i = 0; i < size; i++)
		func(array[i]);
}

template<class T>
void print(T value)
{
	PRINT_COLOR(GREEN, "value = " << value);
}