/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:34:36 by joe               #+#    #+#             */
/*   Updated: 2024/02/26 19:34:54 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANA_HPP
#define __HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"


class	HumanA
{
	private:
		std::string	_name;
		Weapon	&_weapon;

	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		
		void	attack(void);
};

#endif