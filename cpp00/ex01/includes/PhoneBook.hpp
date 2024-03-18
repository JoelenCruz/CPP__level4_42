/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:58:15 by joe               #+#    #+#             */
/*   Updated: 2024/02/22 19:13:31 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>		// std::setw
# include <iostream>	// std::cout, std::cin, std::endl
# include <string>		// std::getline, std::string
# include <sstream>
# include "Contact.hpp"

# define ADD "ADD"
# define EMPTY ""
# define EXIT "EXIT"
# define CTRL_D "CTRL+D"
# define SEARCH "SEARCH"
# define SIZE 8

class PhoneBook
{
	private:
		Contact	_contacts[SIZE];
		unsigned int	_index;
		
		std::string	_get_input(std::string const field);
		void		_set_contact(Contact contact);
		void		_display_phonebook_header(void);
		void		_display_contacts(int i) const;
		void		_display_phonebook_footer(void);
		void		_display_contact_value(std::string value) const;
		bool 		_only_digits(const std::string& str);
		int			ft_stoi(std::string str);

	
	public:
		PhoneBook(void);
		~PhoneBook(void);
        
		void     _print_n_times(char c, int n);
		void	prompt_add(void);
		void	prompt_search(void);
};

#endif