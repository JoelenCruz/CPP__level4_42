/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:06:27 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/21 19:08:04 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Cat.hpp"
#include "Dog.hpp"

/**
 * @brief Testing what the subject asked.
 * 
 */
void	testSubject(void)
{
	size_t			count = 3;
	
	/*
	Can a pointer to abstract class be created?
	
	Yes we can create a pointer to an abstract class, which could be actually 
	pointing to the objects of its derived classes. In this way, a container 
	of base class pointers can be created which can also store derived class 
	objects.

	https://www.geekinterview.com/question_details/87951
	https://stackoverflow.com/questions/5019046/reference-to-abstract-class
	*/
	const AAnimal	*animals[count];

	std::cout << "\nCalling Constructors=====================" << std::endl;
	for (size_t i = 0; i <= count; i++)
	{
		if (i % 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	
	std::cout << "\nChecking Classes=========================" << std::endl;
	for (size_t i = 0; i <= count; i++)
	{
		if (i % 2)
		{
			std::cout << "Class Cat" << std::endl;
			std::cout << "Type: ";
			PRINT(animals[i]->getName());
			std::cout << "makeSound: ";
			animals[i]->makeSound();
		}
		else
		{
			std::cout << "Class Dog" << std::endl;
			std::cout << "Type: ";
			PRINT(animals[i]->getName());
			std::cout << "makeSound: ";
			animals[i]->makeSound();
		}
		std::cout << std::endl;
	}

	std::cout << "Calling Destructors======================" << std::endl;
	for (size_t i = 0; i <= count; ++i)
		delete animals[i];
}

int	main(void)
{
	// AAnimal	test; // THIS SHOULD NOT COMPILE!!!

	testSubject();

	std::cout << "\nCalling Cat Constructors=================" << std::endl;
	Cat	cat;
	Cat	cat2;
	Cat	copyCat(cat);
	cat = cat2;

	std::cout << "\nDisplay Cats=============================" << std::endl;
	PRINT(cat);
	PRINT(copyCat);

	std::cout << "Change Cats Ideas========================" << std::endl;
	std::cout << "[cat]Idea number 42" << std::endl;
	PRINT(cat.getIdea(42));
	std::string	empty("testing copy...");
	cat.setIdea(42, empty);
	PRINT(cat.getIdea(42));

	std::cout << "[copyCat]Idea number 42" << std::endl;
	PRINT(copyCat.getIdea(42));

	std::cout << "\nCalling Dog Constructors=================" << std::endl;
	Dog	dog;
	Dog	dog2;
	Dog	copyDog = dog;
	dog = dog2;

	std::cout << "\nDisplay Dogs=============================" << std::endl;
	PRINT(dog);
	PRINT(copyDog);

	std::cout << "Change Dogs Ideas========================" << std::endl;
	std::cout << "[dog]Idea number 42" << std::endl;
	PRINT(dog.getIdea(42));
	empty = "testing assignment...";
	dog.setIdea(42, empty);
	PRINT(dog.getIdea(42));

	std::cout << "[copyDog]Idea number 42" << std::endl;
	PRINT(copyDog.getIdea(42));

	std::cout << "\nCalling Destructors======================" << std::endl;

	return(0);
}