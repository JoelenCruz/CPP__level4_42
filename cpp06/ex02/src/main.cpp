/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:59:06 by joe               #+#    #+#             */
/*   Updated: 2024/07/09 19:27:07 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base	*generate(void)
{
	Base	*random;
	std::srand(std::time(0)); 
	int		type = std::rand() % 3;
	
	switch (type)
	{
		
		case 0 : random = new A; break;
		case 1 : random = new C; break;
		case 2 : random = new B; break;
	}
	PRINT_COLOR(RED, type);
	return (random);
}


void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
	{
		PRINT_COLOR(PINK, "Class A.");
	}
	else if (dynamic_cast<B *>(p))
	{
		PRINT_COLOR(PINK, "Class B.");
	}
	else if (dynamic_cast<C *>(p))
	{
		PRINT_COLOR(PINK, "Class C.");
	}
	else
	{
		PRINT_COLOR(RED, "Invalid type.")
	}
}


void	identify(Base &p)
{
	try {
		(void)dynamic_cast<A &>(p);PRINT_COLOR(PINK, "Class A.");
		}
	catch(std::exception &e) {}

	try {
		(void)dynamic_cast<B &>(p);PRINT_COLOR(PINK, "Class B.");
		}
	catch(std::exception &e) {}
	
	try {
		(void)dynamic_cast<C &>(p);PRINT_COLOR(PINK, "Class C.");
		}
	catch(std::exception &e) {}
}

int	main(void)
{
	PRINT_COLOR(YELLOW, "--------------TEST 01: Passing a random class (A, B or C)-------------")
	Base * test_01 = generate();
	identify(test_01);
	std::cout << "Identify by reference: ";
	identify(*test_01);
	std::cout << "\n";
	delete test_01;

	PRINT_COLOR(YELLOW, "--------------TEST 02: Error handling (passing the Base class)---------")
	Base test_02;
	std::cout << "Identify by pointer: ";
	identify(&test_02);
	std::cout << "Identify by reference: ";
	identify(test_02);
	std::cout << "\n";

	return (0);
}