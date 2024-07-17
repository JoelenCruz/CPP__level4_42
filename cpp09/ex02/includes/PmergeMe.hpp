/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:04:41 by joe               #+#    #+#             */
/*   Updated: 2024/07/17 00:52:24 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>
#include <sys/time.h>
# include <climits>


// =============================================================================
// macros
// =============================================================================

#define RESET_COLOR "\033[0m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define PINK "\033[35m"

#define PRINT_COLOR(color, message) std::cout << color << message << RESET_COLOR << std::endl;
#define PRINT_COLOR_N(color, message) std::cout << color << message << RESET_COLOR;

// =============================================================================
// Class
// =============================================================================

class PmergeMe 
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;

		// struct timeval vec_start;
		// struct timeval vec_end;

		void mergeVector(int left, int mid, int right);

		void mergeDeque(int left, int mid, int right);
		void fordJohnsonSortVector(int left, int right);
		void fordJohnsonSortDeque(int left, int right);
		

	public:
		PmergeMe();
		PmergeMe(int argc, char* argv[]);
		PmergeMe(const PmergeMe& a);
		~PmergeMe();

		void initVector(int size, char** args);
		void initDeque(int size, char** args);

		void insertionSortVector(int left, int right);
		void insertionSortDeque(int left, int right);
		void printVector(std::string color) const ;
		void printDeque(std::string color) const ;
		void measureExecutionTimeVector();
		void measureExecutionTimeDeque();


		class JustNumbers : public std::exception
		{
			public:
			const char* what() const throw();
		};
		
};