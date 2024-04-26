/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:07:20 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/21 16:40:14 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

int main( void )
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;//should not create a leakcd ..
    delete i;

	PRINT("#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-")
	PRINT("\n")

    Dog basic;
    {
        Dog tmp = basic;
    }

	PRINT("#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-")
	PRINT("\n")

    const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
    for ( int i = 0; i < 4; i++ ) {
        delete animals[i];
    }

    return 0;
}


// void	testSubject(void)
// {
// 	size_t			count = 3;
// 	const Animal	*animals[count];

// 	PRINT("\nCalling Constructors=====================");
// 	for (size_t i = 0; i <= count; i++)
// 	{
// 		if (i % 2)
// 			animals[i] = new Cat();
// 		else
// 			animals[i] = new Dog();
// 	}
	
// 	PRINT("\nChecking Classes=========================");
// 	for (size_t i = 0; i <= count; i++)
// 	{
// 		if (i % 2)
// 		{
// 			std::cout << "Class Cat" << std::endl;
// 			std::cout << "Type: ";
// 			PRINT(animals[i]->getName());
// 			std::cout << "makeSound: ";
// 			animals[i]->makeSound();
// 		}
// 		else
// 		{
// 			std::cout << "Class Dog" << std::endl;
// 			std::cout << "Type: ";
// 			PRINT(animals[i]->getName());
// 			std::cout << "makeSound: ";
// 			animals[i]->makeSound();
// 		}
// 		std::cout << std::endl;
// 	}

// 	PRINT("\nCalling Destructors======================");
// 	for (size_t i = 0; i <= count; ++i)
// 		delete animals[i];
// }

// int	main(void)
// {
// 	testSubject();

// 	PRINT("\nCalling Cat Constructors=================");
// 	Cat	cat;
// 	Cat	cat2;
// 	Cat	copyCat(cat);
// 	cat = cat2;

// 	PRINT("\nDisplay Cats=============================");
// 	PRINT(cat);
// 	PRINT(copyCat);

// 	PRINT("\nChange Cats Ideas========================")
// 	PRINT("\n[cat]Idea number 42")
// 	PRINT(cat.getIdea(42));
// 	std::string	empty("testing copy...");
// 	cat.setIdea(42, empty);
// 	PRINT(cat.getIdea(42));

// 	PRINT("\n[copyCat]Idea number 42")
// 	PRINT(copyCat.getIdea(42));

// 	PRINT("\nCalling Dog Constructors=================")
// 	Dog	dog;
// 	Dog	dog2;
// 	Dog	copyDog = dog;
// 	dog = dog2;

// 	PRINT("\nDisplay Dogs=============================");
// 	PRINT(dog);
// 	PRINT(copyDog);

// 	PRINT("\nChange Dogs Ideas========================");
// 	PRINT("\n[dog]Idea number 42");
// 	PRINT(dog.getIdea(42));
// 	empty = "testing assignment...";
// 	dog.setIdea(42, empty);
// 	PRINT(dog.getIdea(42));

// 	PRINT("\n[copyDog]Idea number 42");
// 	PRINT(copyDog.getIdea(42));

// 	PRINT("\n\nCalling Destructors======================");
// 	return(0);
// }