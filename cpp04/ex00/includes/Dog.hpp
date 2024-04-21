/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:42:05 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/21 16:42:27 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		//* Orthodox Canonical Form methods *//
		Dog(void);
		Dog(Dog const &src);
		Dog &operator = (Dog const &rhs);
		virtual	~Dog(void);

		//* Member Functions *//
		void	makeSound(void) const;
};

std::ostream &operator << (std::ostream &o, Dog const &i);