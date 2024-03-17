/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:07:24 by joe               #+#    #+#             */
/*   Updated: 2024/02/22 19:26:43 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>
#include <string>

//TODO: add crtl + d to exit the program (ok), falha ao usar dentro do programa

//TODO: empty fields exist? (OK)

//TODO: add a check for the input of the phone number (OK)


int	PhoneBook::ft_stoi(std::string str)
{
	std::stringstream	ss;
	int					num;

	ss << str;
	ss >> num;
	return (num);
}

int	main(void)
{
	std::string	cmd;
	PhoneBook	phonebook;

	phonebook._print_n_times('*', 60);
	std::cout << "\n\t ---------------------" << std::endl;
	std::cout << "\t|  ^ ^     Welcome    |" << std::endl;
	std::cout << "\t| (O,O)      to       |" << std::endl;
	std::cout << "\t| (   )   PhoneBook   |" << std::endl;
	std::cout << "\t ---------------------\n" << std::endl;
	
	while (cmd != EXIT)
	{
		std::cout << "\tPlease chose one of the following options:" << std::endl;
		std::cout << "\t<ADD>  to add a new contact 🆕" << std::endl;
		std::cout << "\t<SEARCH> to look for a contact 🔍" << std::endl;
		std::cout << "\t<EXIT> to quit the program ❌\n" << std::endl << "> ";
		phonebook._print_n_times('*', 60);

		std::getline(std::cin, cmd);
		
		if (std::cin.eof()) //CTRL-D
            break;
		else if (cmd == ADD)
			phonebook.prompt_add();
		else if (cmd == SEARCH)
			phonebook.prompt_search();
		else if (cmd != EXIT)
			std::cout << "Command <" << cmd << "> is invalid" << std::endl;
	}
	std::cout << "💀 >>> Quitting the program <<< 💀" <<std::endl;
	return (0);
}