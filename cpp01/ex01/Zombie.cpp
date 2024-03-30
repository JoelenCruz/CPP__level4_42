/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:08:31 by joe               #+#    #+#             */
/*   Updated: 2024/03/29 16:21:28 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// *=============================================================================
// *CONSTRUCTOR AND DESTRUCTOR
// *=============================================================================

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


// *=============================================================================
// *PUBLIC FUNCTIONS
// *=============================================================================

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->_name = name;
}   

