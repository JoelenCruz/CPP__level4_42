/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:50:15 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/21 13:50:33 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		//* Orthodox Canonical Form methods *//
		FragTrap(void);
		FragTrap(std::string const &name);
		FragTrap(FragTrap const &src);
		~FragTrap(void);
		FragTrap &operator = (FragTrap const &rhs);

		//* Member Functions *//
		void	highFivesGuy(void);
};

std::ostream & operator << (std::ostream  &o, FragTrap const &i);