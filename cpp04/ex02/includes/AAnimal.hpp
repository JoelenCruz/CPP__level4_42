/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:09:18 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/21 16:18:32 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define PRINT(x) std::cout << x << std::endl;

class AAnimal
{
	protected:
		std::string	_name;

	public:
		/* Orthodox Canonical Form methods */
		AAnimal(void);
		AAnimal(std::string const &type);
		AAnimal(AAnimal const &src);
		AAnimal &operator = (AAnimal const &rhs);
		virtual	~AAnimal(void);

		/* Member Functions */
		std::string	getName(void) const;
		virtual void	makeSound(void) const = 0;
};

std::ostream &operator << (std::ostream &o, AAnimal const &i);