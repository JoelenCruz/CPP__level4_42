/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:04:41 by joe               #+#    #+#             */
/*   Updated: 2024/07/12 00:15:29 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
#include <vector>
typedef std::vector<int>	intv;


#define RESET_COLOR "\033[0m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define PINK "\033[35m"

#define PRINT_COLOR(color, message) std::cout << color << message << RESET_COLOR << std::endl;


// =============================================================================
// Class
// =============================================================================

class Span 
{
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;

	public:
		/* Orthodox Canonical Form methods */
		Span();
		Span(unsigned int);
		Span(Span const &src);
		~Span();
		Span &operator = (Span const &rhs);

		void populateSpan(intv::iterator begin, intv::iterator end);
		void addNumber(int number);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);

		class SpanIsFullException : public std::exception
		{
			public:
			const char* what(void) const throw();
		};

		class NotEnoughNumbersException : public std::exception
		{
			public:
			const char* what(void) const throw();
	};
};