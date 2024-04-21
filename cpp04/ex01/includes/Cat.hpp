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
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*_brain;

	public:
		Cat(void);
		Cat(Cat const &src);
		Cat &operator = (Cat const &rhs);
		virtual	~Cat(void);

		void	makeSound(void) const;
		std::string	getIdea(size_t i) const;
		void	setIdea(size_t i, std::string &idea);
		Brain	*getBrain(void) const;
};

std::ostream &operator << (std::ostream &o, Cat const &i);