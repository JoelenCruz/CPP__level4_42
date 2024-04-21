/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:09:18 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/21 16:18:32 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#pragma once

#define PRINT(x) std::cout << x << std::endl;

class Animal
{
    protected:
        std::string  _name;
            
    
    public:
        Animal(void);
        Animal(std::string const &name);
        Animal(Animal const &src);
        Animal &operator = (Animal const &rhs);
        virtual ~Animal(void);

        std::string getName(void) const;
        virtual void makeSound(void) const;       
};

std::ostream &operator << (std::ostream &o, Animal const &i);