/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:04:41 by joe               #+#    #+#             */
/*   Updated: 2024/06/29 14:27:04 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>	//std::time();
#include <cstdlib>	//std::rand(); std::srand()
#include <ctime>	//std::time();


#define RESET_COLOR "\033[0m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define PINK "\033[35m"

#define PRINT_COLOR(color, message) std::cout << color << message << RESET_COLOR << std::endl;

// =============================================================================
// CLASS
// =============================================================================

class  Base
{
	public:
		virtual~Base(void);
};