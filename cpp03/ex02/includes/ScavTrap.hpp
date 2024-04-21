/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:40:46 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/21 14:47:45 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	public:
	//* Orthodox Canonical Form methods*//
		ScavTrap(void);
		ScavTrap(std::string const &name);
		ScavTrap(ScavTrap const &src);
		~ScavTrap(void);
		ScavTrap &operator = (ScavTrap const &rhs);

		//* Member functions *//
		void	attack(const std::string &target);
		void	guardGate(void);
};

std::ostream & operator << (std::ostream  &o, ScavTrap const &i);