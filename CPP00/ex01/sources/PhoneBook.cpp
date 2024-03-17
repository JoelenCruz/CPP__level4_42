/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:16:19 by joe               #+#    #+#             */
/*   Updated: 2024/02/22 19:12:16 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


// *=============================================================================
// *CONSTRUCTOR AND DESTRUCTOR
// *=============================================================================

PhoneBook::PhoneBook(void): _contacts(), _index(0){
    return;
}

PhoneBook::~PhoneBook(void){
    return;
}

// *=============================================================================
// *PRIVATE FUNCTIONS
// *=============================================================================

bool PhoneBook::_only_digits(const std::string& str) {
    // Verificar se todos os caracteres da string são dígitos
    std::string::const_iterator it = str.begin();
    while (it != str.end()) {
        if (!std::isdigit(*it)) {
            return false;
        }
        ++it;
    }
    return true;
}


std::string PhoneBook::_get_input(std::string const field) {
    std::string input;

    std::cout << "Please enter " << field << ":" << std::endl << "> ";

    // Lê a entrada do usuário
    std::getline(std::cin, input);

	if (std::cin.eof()) //CTRL-D
            return EXIT;

    // Verifica se a entrada está vazia
    else if (input.empty()) {
        std::cout << "Please enter a value." << std::endl;
        return _get_input(field); // Chama recursivamente a função para solicitar novamente a entrada
    }

	else if(field == "Phone Number"){
		if (_only_digits(input) == false)
		{
			std::cout << "Please enter a valid phone number." << std::endl;
			return _get_input(field);
		}
		
	}

    return input;
}



void	PhoneBook::_set_contact(Contact contact)
{
	if (_index == SIZE)
		_index = 1;
	else
		_index++;
	_contacts[_index - 1] = contact;
}

void	PhoneBook::_display_phonebook_header(void)
{
	_print_n_times('*', 60);
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname";
	std::cout << "|" << std::setw(10) << "Phone Number";
	std::cout << "|" << std::endl;
	_print_n_times('*', 60);
}

void	PhoneBook::_display_contact_value(std::string value) const
{
	if (value.length() > 10)
	{
		value.resize(9);
		value += ".";
	}
	std::cout << std::setw(10) << value << "|";
}

void	PhoneBook::_display_contacts(int i) const
{
	std::cout << "|" << std::setw(10) << i + 1 << "|";
	_display_contact_value(this->_contacts[i].get_first_name());
	_display_contact_value(this->_contacts[i].get_last_name());
	_display_contact_value(this->_contacts[i].get_nickname());
	_display_contact_value(this->_contacts[i].get_phone_number());
	std::cout << std::endl;
}


void	PhoneBook::_display_phonebook_footer(void)
{
	_print_n_times('*', 60);
	std::cout << std::endl;
}

// *=============================================================================
// *PUBLIC FUNCTIONS
// *=============================================================================

void	PhoneBook::_print_n_times(char c, int n)
{
	std::cout << std::string(n, c) << std::endl;
}


/**
 * @brief Displays the prompt to add a new contact.
 */
void	PhoneBook::prompt_add(void)
{
	Contact contact;
	
	contact.set_first_name(_get_input("First Name"));
	contact.set_last_name(_get_input("Last Name"));
	contact.set_nickname(_get_input("Nickname"));
	contact.set_phone_number(_get_input("Phone Number"));
	contact.set_darkest_secret(_get_input("Darkest Secret"));
	_set_contact(contact);
}

/**
 * @brief Displays the prompt to search a contact in the phonebook.
 * 
 */
void	PhoneBook::prompt_search(void)
{
	std::string	input;

	if (!_index)
	{
		std::cout << "Error: No contacts to display. ADD a contact first" << std::endl;
		return ;
	}
	_display_phonebook_header();
	for (int i = 0; i <= 7; i++)
	{
		_display_contacts(i);
		_print_n_times('*', 60);
		if (i == 7)
			std::cout << std::endl;
	}
	input = _get_input("an index to select a contact");
	if (ft_stoi(input) > 0 && ft_stoi(input) < 9)
		_contacts[ft_stoi(input) - 1].display();
	else
	{
		// std::system("clear");
		return ;
	}
}