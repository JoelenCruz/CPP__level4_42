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


void	testSubject(void)
{
	size_t			count = 3;
	const Animal	*animals[count];

	PRINT("\nCalling Constructors#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#");
	for (size_t i = 0; i <= count; i++)
	{
		if (i % 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	
	PRINT("\nChecking Classes#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#");
	for (size_t i = 0; i <= count; i++)
	{
		if (i % 2)
		{
			PRINT("Class Cat");
			PRINT("Type: ");
			PRINT(animals[i]->getName());
			PRINT("makeSound: ");
			animals[i]->makeSound();
		}
		else
		{
			PRINT("Class Dog");
			PRINT("Type: ");
			PRINT(animals[i]->getName());
			PRINT("makeSound: ");
			animals[i]->makeSound();
		}
		PRINT("\n");
	}

	PRINT("Calling Destructors======================");
	for (size_t i = 0; i <= count; ++i)
		delete animals[i];
}

int	main(void)
{
	testSubject();

	PRINT("\nCalling Cat Constructors=================");
	Cat	cat;
	Cat	cat2;
	Cat	copyCat(cat);
	cat = cat2;

	PRINT("Display Cats=============================");
	PRINT(cat);
	PRINT(copyCat);

	std::cout << "Change Cats Ideas========================" << std::endl;
	std::cout << "[cat]Idea number 2" << std::endl;
	PRINT(cat.getIdea(2));
	std::string	empty("testing copy...");
	cat.setIdea(2, empty);
	PRINT(cat.getIdea(2));

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