/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:47:58 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/07/12 00:27:24 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>


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

void Span::addNumber(int number) 
{
    if (_numbers.size() >= _maxSize) 
    {
        throw SpanIsFullException();
    }
    _numbers.push_back(number);
}

void Span::populateSpan(intv::iterator begin, intv::iterator end) {
    while (begin != end) {
        if (_numbers.size() >= _maxSize) {
            throw SpanIsFullException();
        }
        _numbers.push_back(*begin);
        ++begin;
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

unsigned int	Span::shortestSpan(void)
{	
	if (this->_numbers.size() < 2)
		NotEnoughNumbersException();

	intv	sorted(this->_numbers);
	std::sort(sorted.begin(), sorted.end());
	int	previous = sorted.front();
	intv::iterator	it = sorted.begin();
	it++;
	int	span = *it - previous;
	for (; it != sorted.end(); it++)
	{
		if (*it - previous < span)
			span = *it - previous;
		previous = *it;
	}
	return (span);
}