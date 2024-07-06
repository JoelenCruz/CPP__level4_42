/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:59:06 by joe               #+#    #+#             */
/*   Updated: 2024/06/29 15:03:41 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base	*generate(void)
{
	Base	*random;
	int		type = std::rand() % 3;
	
	switch (type)
	{
		case 0 : random = new A; break;
		case 1 : random = new B; break;
		case 2 : random = new C; break;
	}
	return (random);
}

/**
 * @brief Prints the actual type of the object pointed to by p: "A", "B" or "C"
 * 
 * @param p the Base pointer to check.
 */
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

/**
 * @brief Prints the actual type of the object referenced by p: "A", "B" or "C"
 * 
 * @param p the Base reference to check.
 */
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
	PRINT_COLOR(YELLOW, "TEST 01: Passing a random class (A, B or C)")
	Base * test_01 = generate();
	std::cout << "Identify by pointer: ";
	identify(test_01);
	std::cout << "Identify by reference: ";
	identify(*test_01);
	std::cout << "\n";
	delete test_01;

	PRINT_COLOR(YELLOW, "TEST 02: Error handling (passing the Base class)")
	Base test_02;
	std::cout << "Identify by pointer: ";
	identify(&test_02);
	std::cout << "Identify by reference: ";
	identify(test_02);
	std::cout << "\n";

	return (0);
}