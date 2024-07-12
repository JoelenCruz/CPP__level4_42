/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:04:41 by joe               #+#    #+#             */
/*   Updated: 2024/07/12 22:25:45 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>		
#include <algorithm>	
#include <vector>			
#include <climits> 		
#include <ctime> 	
 
typedef std::vector<int>	int_vector;

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
		int_vector _numbers;

	public:
		/* Orthodox Canonical methods */
		Span();
		Span(unsigned int);
		Span(Span const &src);
		~Span();
		Span &operator = (Span const &rhs);

		int_vector const		&getRange(void) const;
		void populateSpan(int_vector::iterator begin, int_vector::iterator end);
		void addNumber(int number);
		void addNumber(int_vector::iterator begin, int_vector::iterator end);
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