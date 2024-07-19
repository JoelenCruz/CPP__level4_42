/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:04:41 by joe               #+#    #+#             */
/*   Updated: 2024/07/19 18:12:17 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>
#include <sys/time.h>
#include <sys/time.h>
# include <climits>
#include <algorithm> 
 #include <iomanip> // std::setprecision



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

		// Vector functions
		void initVector(int size, char** args);
		void printVector(const std::string& color) const ;
		bool areAllEqualVector(std::vector<int>& vector);
		std::vector<int> jacobsthalSequential(int number); 
		std::vector<int> jacobsthalDiff(int number);
		std::vector<int> sortVector(std::vector<int> vec);
		void generatePairs(const std::vector<int>& vec, std::vector<std::pair<int, int> >& pairs);
		void handlePairs(const std::vector<std::pair<int, int> >& pairs, 
                            std::vector<int>& pend, 
                            std::vector<int>& sorted);
		void mergeAndInsert(std::vector<int>& pend, 
                              std::vector<int>& sorted, 
                              int last, 
                              bool odd); 
		void insertSorted(std::vector<int>& sorted, int value);
		void fordJohnsonSortVector();
		void measureExecutionTimeVector();
		

		// Deque functions
		void initDeque(int size, char** args);
		void printDeque(const std::string& color) const;
		bool areAllEqualDeque(std::deque<int>& deque);
		std::deque<int> jacobsthalSequentialDeque(int number); 
		std::deque<int> jacobsthalDiffDeque(int number);
		std::deque<int> sortDeque(std::deque<int> inputdeque);  
		
		void generatePairsDeque(const std::deque<int>& vec, std::deque<std::pair<int, int> >& pairs);
		void handlePairsDeque(const std::deque<std::pair<int, int> >& pairs,
							std::deque<int>& pendingElements, 
							std::deque<int>& sortedElements); 
		void mergeAndInsertDeque(std::deque<int>& pendingElements, 
								std::deque<int>& sortedElements, 
								int lastElement, 
								bool isOdd);
		void insertSortedDeque(std::deque<int>& sorted, int value); 
		void fordJohnsonSortDeque();
		void measureExecutionTimeDeque(); 
		

	public:
		PmergeMe();
		PmergeMe(int argc, char* argv[]);
		PmergeMe(const PmergeMe& a);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		class JustNumbers : public std::exception
		{
			public:
			const char* what() const throw();
		};

		class AllEqual : public std::exception
		{
			public:
			const char* what() const throw();
		};

		class ErrorParameter : public std::exception
		{
			public:
			const char* what() const throw();
		};
		
};