/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:49:42 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/14 21:01:49 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define PRINT(x) std::cout << x << std::endl;

class ClapTrap
{
    protected:
        std::string _name;
        int _hitPoints;
        int _attacksPoints;
        int _damage;
        
        //* Construtors for derived classes *//
		ClapTrap(std::string const &name, int hitPoints, int attacksPoints, int damage);
		ClapTrap(int hitPoints, int attacksPoints, int Damage);

    public:
        ClapTrap(void); //consturtor
        ClapTrap(std::string const name);
        ClapTrap(ClapTrap const &src);
        ClapTrap &operator = (ClapTrap const &rhs);
        ~ClapTrap(void); //destrutor 


        //*Getters *//
		std::string	getName(void) const;
		int		getHitPoints(void) const;
		int		getAttacksPoints(void) const;
		int		getDamage(void) const;

		//* Setters *//
		void	setName(std::string const &name);
		void	setHitPoints(int const hitPoints);
		void	setAttacksPoints(int const energyPoints);
		void	setDamage(int const attackDamage);
		
        //* Member functions *//
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

std::ostream & operator << (std::ostream &o, ClapTrap const &i);
