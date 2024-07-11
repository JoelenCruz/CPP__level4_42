/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:04:41 by joe               #+#    #+#             */
/*   Updated: 2024/07/10 00:12:12 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

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

// =============================================================================
// Class
// =============================================================================

template<typename T>

class Array
{
	private:
        T* _array;
        unsigned int _size;

	public:
	/* Orthodox Canonical Form Methods */
        Array(void)
        {
            this->_array = new T[0];
            this->_size = 0;
        };
        
        Array(unsigned int n)
        {
            this->_array = new T[n];
            this->_size = n;
        };
        
        ~Array(void)
        {
            delete[] this->_array;
        };
        
        Array(const Array& a)
        {
            this->_size = a.size();
            this->_array = new T[a.size()];
            for (unsigned int i = 0; i < _size; i++)
            {
                this->_array[i] = a[i];
            }
        };
        
        Array& operator=(const Array& a)
        {
            delete[] this->_array;
            this->_size = a.size();
            this->_array = new T[a.size()];
            for (unsigned int i = 0; i < _size; i++)
            {
                this->_array[i] = a[i];
            }
            return (*this);
        };
        
        T&	operator[](unsigned int index) const
        {
            if (index >= this->_size)
                throw OutOfBoundsException();
            return (this->_array[index]);
        };

	    // Member functions
        unsigned int	size(void) const
        {
            return (this->_size);
        }
        
        // Exceptions
        class OutOfBoundsException : public std::exception
        {
            public:
            const char* what() const throw()
            {
                return "Exception: The index you tried to access is out of array bounds!\n";
            }
        };
};
