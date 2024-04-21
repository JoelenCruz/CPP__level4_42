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

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


//*Prints polymorphism tests using classes pointers.
void	pointersTest(void)
{
	PRINT("Subject Tests Using Pointers:")
	PRINT("\e[1;3;32m\n[pointersTest] Constructors list:\e[0m")
	
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	const WrongAnimal *h = new WrongAnimal();
	const WrongAnimal *g = new WrongCat();
	PRINT("#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-\n")
	
	/* Printing types */
	PRINT("\e[1;3;32m\n[pointersTest] Printing Types:\e[0m")
	std::cout << "🧬 Animal: " << meta->getName() << " " << std::endl;
	std::cout << "🐕 Dog: " << j->getName() << " " << std::endl;
	std::cout << "🐈 Cat: " << i->getName() << " " << std::endl;
	std::cout << "❌🧬 WrongAnimal: " << h->getName() << " " << std::endl;
	std::cout << "❌🐈 WrongCat: " << g->getName() << " " << std::endl;
	PRINT("#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-\n")

	/* Making Sounds */
	PRINT("\e[1;3;32m\n[pointersTest] Making Sounds:\e[0m")
	std::cout << "❌🐈 WrongCat says: ";
	g->makeSound();
	std::cout << "❌🧬 WrongAnimal says: ";
	h->makeSound();
	std::cout << "🐈 Cat says: ";
	i->makeSound(); //will output the cat sound!
	std::cout << "🐕 Dog says: ";
	j->makeSound();
	std::cout << "🧬 Animal says: ";
	meta->makeSound();
	PRINT("#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-\n")


	PRINT("\e[1;3;32m\n[pointersTest] Destructors list:\e[0m")
	delete g;
	delete h;
	delete i;
	delete j;
	delete meta;
}


void	noPointerTest(void)
{
	PRINT("\nTests Without Pointers:");
	PRINT("\e[1;3;35m\n[noPointerTest] Constructors list:\e[0m");
	const Animal pet1 = Animal();
	const Animal pet2 = Cat();
	const Animal pet3 = Dog();
	const WrongAnimal notPet1 = WrongAnimal();
	const WrongAnimal notPet2 = WrongCat();
	PRINT("#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-\n")

	/* Printing types */
	std::cout << "\e[1;3;35m\n[noPointerTest] Printing Types:\e[0m" << std::endl;
	std::cout << "🧬 Animal: " << pet1.getName() << " " << std::endl;
	std::cout << "🐈 Cat: " << pet2.getName() << " " << std::endl;
	std::cout << "🐕 Dog: " << pet3.getName() << " " << std::endl;
	std::cout << "❌🧬 WrongAnimal: " << notPet1.getName() << " " << std::endl;
	std::cout << "❌🐈 WrongCat: " << notPet2.getName() << " " << std::endl;
	PRINT("#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-\n")

	/* Making Sounds */
	std::cout << "\e[1;3;35m\n[noPointerTest] Making Sounds:\e[0m" << std::endl;
	std::cout << "🧬 Animal says: ";
	pet1.makeSound();
	std::cout << "🐈 Cat says: ";
	pet2.makeSound(); //will output the cat sound!
	std::cout << "🐕 Dog says: ";
	pet3.makeSound();
	std::cout << "❌🧬 WrongAnimal says: ";
	notPet1.makeSound();
	std::cout << "❌🐈 WrongCat says: ";
	notPet2.makeSound();
	PRINT("#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-\n")

	PRINT("e[1;3;35m\n[noPointerTest] Destructors list:\e[0m")
	PRINT("#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-\n")
}

int	main(void)
{
	/*
	Class Pointer VS Class Instance
	
	- Allocation on the heap is not as cheap as allocation on the stack.
	- Objects on the stack must be smaller, for variety of reasons 
	(cost of copy construction, locality of reference, stack overflow, etc.)
	- Using pointers and references can remove compilation dependencies and 
	consequently reduce the compilation times.
	- Objects on the stack are cleaned-up automatically in case of exceptions. 
	- Objects on the stack tend to be closer to each other in memory, 
	and this helps caching and paging.

	You can only use polymorphy with instance pointers or references, 
	not with instances.
	https://cplusplus.com/forum/general/37813/
	*/
	
	/* Subject tests */
	pointersTest();
	PRINT("#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-")
	noPointerTest();

	return(0);
}