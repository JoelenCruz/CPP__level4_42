/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:24:34 by joe               #+#    #+#             */
/*   Updated: 2024/03/29 17:49:29 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// *=============================================================================
// *CONSTRUTOR AND DESTRUCT
// *=============================================================================

Harl::Harl(void)
{
    return;
}

Harl::~Harl(void)
{
    return;
}   
// *=============================================================================
// *FUNCTION
// *=============================================================================

void Harl::debug(void)
{
    PRINT("");
    PRINT("[Debug]");
    PRINT("I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.");
	PRINT("I really do!");
	PRINT("");
}

void	Harl::info(void)
{
	PRINT("");
	PRINT("[INFO]")
	PRINT("I cannot believe adding extra bacon costs more money.");
	PRINT("You didn’t put enough bacon in my burger.");
	PRINT("If you did, I wouldn’t be asking for more!");
	PRINT("");
}

void	Harl::warning(void)
{
	PRINT("");
	PRINT("[WARNING]")
	PRINT("I think I deserve to have some extra bacon for free.");
	PRINT("I’ve been coming for years whereas you started working here since last month.");
	PRINT("");
}

void	Harl::error(void)
{
	PRINT("");
	PRINT("[ERROR]")
	PRINT("This is unacceptable!");
	PRINT("I want to speak to the manager now.");
	PRINT("");
}

void	Harl::complain(std::string level)
{
    //array de strings para os possiveis levels
    std::string levels[4] = 
    {
        "DEBUG", 
        "INFO", 
        "WARNING", 
        "ERROR"
    };
    
    //array de ponteiros que apontam para as funções membros de harl
    void (Harl::*functions[4])(void) = 
    {
        &Harl::debug, 
        &Harl::info, 
        &Harl::warning, 
        &Harl::error
    };
    

    for (size_t i = 0; i < 4; i++)
    {
        if (level == levels[i])
            return ((this->*functions[i])());
    }
    ERROR("Invalid option");
}
