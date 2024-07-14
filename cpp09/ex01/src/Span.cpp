/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:47:58 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/07/13 17:06:50 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"


// =============================================================================
// Exceptions
// =============================================================================

const char* Span::SpanIsFullException::what() const throw() {
    return "Span is full";
}

const char* Span::NotEnoughNumbersException::what() const throw() {
    return "Not enough numbers in Span";
}


// =============================================================================
// Constructors and Destructor
// =============================================================================

Span::Span() : _maxSize(1), _numbers(0) 
{
    PRINT_COLOR(BLUE, "Span default constructor called");
}

Span::Span(unsigned int N) : _maxSize(N), _numbers(0) 
{
    PRINT_COLOR(BLUE, "Span parameterized constructor called");
}

Span::Span(Span const &src)
{
    PRINT_COLOR(BLUE, "Span copy constructor called");
	this->_maxSize = src._maxSize;
	this->_numbers = src._numbers;
	return ;
}

Span::~Span() 
{
    PRINT_COLOR(RED, "Span destructor called");
}


Span &Span::operator = (Span const &rhs)
{
    PRINT_COLOR(BLUE, "Span assignation operator called");
	if (this != &rhs)
	{
		this->_maxSize = rhs._maxSize;
		this->_numbers.clear();
		this->_numbers.insert(this->_numbers.end(), rhs._numbers.begin(), rhs._numbers.end());
	}
	return (*this);
}



// =============================================================================
// FUNCTIONS
// =============================================================================

void Span::addNumber(int number) 
{
    if (_numbers.size() >= _maxSize) 
    {
        throw SpanIsFullException();
    }
    _numbers.push_back(number);
}

void	Span::addNumber(int_vector::iterator begin, int_vector::iterator end)
{
	while (begin != end)
	{
		if (this->_numbers.size() == this->_maxSize)
			throw (Span::SpanIsFullException());
		this->_numbers.push_back(*begin);
		begin++;
	}
}
unsigned int Span::longestSpan(void) 
{
    if (_numbers.size() < 2) {
        throw NotEnoughNumbersException();
    }
    std::vector<int> sortedNumbers(_numbers);
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    return static_cast<unsigned int>(sortedNumbers.back() - sortedNumbers.front());
}

unsigned int Span::shortestSpan(void)
{
    if (_numbers.size() < 2)
        throw Span::NotEnoughNumbersException();

    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());

    unsigned int min_distance = INT_MAX;
    for (size_t i = 1; i < sorted.size(); i++)
    {
        unsigned int current_distance = sorted[i] - sorted[i - 1];
        if (current_distance < min_distance)
            min_distance = current_distance;
    }
    return min_distance;
}


