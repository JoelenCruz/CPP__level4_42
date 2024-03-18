/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:53:18 by joe               #+#    #+#             */
/*   Updated: 2024/02/26 19:00:43 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string	stringVAR = "HI THIS IS BRAIN"; //declare a string
	std::string	*stringPTR = &stringVAR; //declare a pointer to the string
	std::string	&stringREF = stringVAR; //declare a reference to the string

	// Printing address
	std::cout << "The memory address of the string variable:\t";
	std::cout << &stringVAR << std::endl;

	std::cout << "The memory address held by stringPTR:\t\t";
	std::cout << stringPTR << std::endl;

	std::cout << "The memory address held by stringREF:\t\t";
	std::cout << &stringREF << std::endl << std::endl;

	// Printing value
	std::cout << "The value of the string variable:\t";
	std::cout << stringVAR << std::endl;

	std::cout << "The value pointed to by stringPTR:\t";
	std::cout << *stringPTR << std::endl;

	std::cout << "The value pointed to by stringREF:\t";
	std::cout << stringREF << std::endl;
}