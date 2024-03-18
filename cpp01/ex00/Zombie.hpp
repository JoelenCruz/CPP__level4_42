/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:08:35 by joe               #+#    #+#             */
/*   Updated: 2024/02/24 13:36:03 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H__
# define ZOMBIE_H__
#include <iostream>

class Zombie
{
    private:
        std::string _name;
    
    public: 
        Zombie(std::string name); //constutor
        ~Zombie(void); //destructor
        
        void announce(void); //function to announce
 };

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif