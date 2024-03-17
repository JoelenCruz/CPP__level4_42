/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:32:36 by joe               #+#    #+#             */
/*   Updated: 2024/02/22 18:26:52 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Contact.hpp"

// *=============================================================================
// *CONSTRUCTOR AND DESTRUCTOR
// *=============================================================================


Contact::Contact(void)
{
	return ;
}


Contact::~Contact(void)
{
	return ;
}

// *=============================================================================
// *GETTERS
// *=============================================================================


void	Contact::set_first_name(std::string firstName)
{
	this->_firstName = firstName;
}


void	Contact::set_last_name(std::string lastName)
{
	this->_lastName = lastName;
}


void	Contact::set_nickname(std::string nickname)
{
	this->_nickname = nickname;
}


void	Contact::set_phone_number(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}


void	Contact::set_darkest_secret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}

// *=============================================================================
// *SETTERS
// *=============================================================================


std::string	Contact::get_first_name(void) const
{
	return (this->_firstName);
}


std::string	Contact::get_last_name(void) const
{
	return (this->_lastName);
}


std::string	Contact::get_nickname(void) const
{
	return (this->_nickname);
}


std::string	Contact::get_phone_number(void) const
{
	return (this->_phoneNumber);
}


std::string	Contact::get_darkest_secret(void) const
{
	return (this->_darkestSecret);
}

// =============================================================================
// UTILS
// =============================================================================


void	Contact::display(void)
{
	std::cout << "First Name:\t" << this->_firstName << std::endl;
	std::cout << "Last Name:\t" << this->_lastName << std::endl;
	std::cout << "Nickname:\t" << this->_nickname << std::endl;
	std::cout << "Phone Number:\t" << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret:\t" << this->_darkestSecret << std::endl;
	std::cout << std::endl;
}