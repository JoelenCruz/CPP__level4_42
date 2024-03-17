/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:08:35 by joe               #+#    #+#             */
/*   Updated: 2024/02/24 15:28:43 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_H__
# define __ZOMBIE_H__
# include <iostream>
# define HORDE_SIZE 10

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