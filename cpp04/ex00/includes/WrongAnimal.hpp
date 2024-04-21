/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:59:25 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/21 17:18:07 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>


#define PRINT(x) std::cout << x << std::endl;

class WrongAnimal
{
	protected:
		std::string	_name;

	public:
		/* Orthodox Canonical Form methods */
		WrongAnimal(void);
		WrongAnimal(std::string const &name);
		WrongAnimal(WrongAnimal const &src);
		WrongAnimal &operator = (WrongAnimal const &rhs);
		~WrongAnimal(void);
		
		/* Member Function */
		std::string	getName(void) const;
		void	makeSound(void) const;
};