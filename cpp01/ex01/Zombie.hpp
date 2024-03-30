/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:08:35 by joe               #+#    #+#             */
/*   Updated: 2024/03/29 16:31:31 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_H__
# define __ZOMBIE_H__
# include <iostream>
# define HORDE_SIZE 5

class	Zombie
{
	private:
		std::string	_name;

	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);

		void	announce(void);
		void	setName(std::string name);
};

Zombie	*zombieHorde(int N, std::string name);
bool  verifyPositive(int number);

#endif