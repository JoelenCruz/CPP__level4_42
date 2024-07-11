/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:31:51 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/07/11 22:41:04 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#define RESET_COLOR "\033[0m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define PINK "\033[35m"

#define PRINT_COLOR(color, message) std::cout << color << message << RESET_COLOR << std::endl;

#include <algorithm> // std::find

// =============================================================================
// Template
// =============================================================================

template<typename T>
void easyfind(T& container, int find)
{
	typename T::iterator it = std::find(container.begin(), container.end(), find);
	if (it == container.end())
		throw std::runtime_error("Element not found");
}

