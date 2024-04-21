/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:41:56 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/21 16:41:58 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		//* Orthodox Canonical Form methods *//
		Cat(void);
		Cat(Cat const &src);
		Cat &operator = (Cat const &rhs);
		virtual	~Cat(void);

		//* Member Functions *//
		void	makeSound(void) const;
};

std::ostream &operator << (std::ostream &o, Cat const &i);