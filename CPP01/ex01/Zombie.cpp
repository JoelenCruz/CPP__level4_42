/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:08:31 by joe               #+#    #+#             */
/*   Updated: 2024/02/24 15:22:51 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) //construtor sem parametros
{
	return ;
}

Zombie::Zombie(std::string name) : _name(name) //comstrutor com parametros
{
   return ;
}

Zombie::~Zombie(void)
{
    std::cout << this->_name << " is dead!" << std::endl;
}


//!functions
void Zombie::announce(void)
{
    std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->_name = name;
}   

