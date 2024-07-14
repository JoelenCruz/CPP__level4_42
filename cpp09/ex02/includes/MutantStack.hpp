/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:04:41 by joe               #+#    #+#             */
/*   Updated: 2024/07/13 16:33:16 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <stack>

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
class MutantStack : public std::stack<T>
{
	public:
	/* Orthodox Canonical methods */
	MutantStack() 
	{
		PRINT_COLOR(BLUE, "🔋 MutantStack default constructor called");
	};
	
	MutantStack(const MutantStack& a) 
	{ 
		PRINT_COLOR(BLUE, "🔋 MutantStack copy constructor called");
		*this = a; 
	};

	~MutantStack() 
	{
		PRINT_COLOR(RED, "🔋 MutantStack destructor called");
	};
	
	MutantStack& operator=(const MutantStack& a) 
	{ 
		std::stack<T>::operator=(a); 
		return (*this);
	};



	/* TEMPLTES */
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator	begin()	
	{ 
		return (std::stack<T>::c.begin()); 
	}
	
	iterator	end() 
	{ 
		return (std::stack<T>::c.end()); 
	}
	
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator	reverse_begin()	
	{ 
		return (std::stack<T>::c.reverse_begin()); 
	}

	
	reverse_iterator	reverse_end()	
	{ 
		return (std::stack<T>::c.reverse_end()); 
	}


	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	const_iterator	const_begin()	
	{ 
		return (std::stack<T>::c.const_begin()); 
	}
	
	const_iterator	const_end() 
	{ 
		return (std::stack<T>::c.const_end()); 
	}
	
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator	const_reverse_begin()	
	{ 
		return (std::stack<T>::c.const_reverse_begin()); 
	}
	const_reverse_iterator	const_reverse_end() 
	{ 
		return (std::stack<T>::c.const_reverse_end()); 
	}
};