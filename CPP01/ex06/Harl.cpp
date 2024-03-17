/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:42:25 by joe               #+#    #+#             */
/*   Updated: 2024/03/01 13:20:52 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

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
	size_t	index;
	std::string levels[4] = 
    {
        "DEBUG", 
        "INFO", 
        "WARNING", 
        "ERROR"
    };
	
    void	(Harl::*f[4])(void) = 
    {
        &Harl::debug, 
        &Harl::info,							
        &Harl::warning, 
        &Harl::error
    };
									
	for (index = 0; index < 4; index++)
		if (level == levels[index])
			break ;
            
	switch (index)
	{
        default:
			ERROR("Invalid option");
			break ;
		case (0):
			(this->*f[index++])();
		case (1):
			(this->*f[index++])();
		case (2):
            (this->*f[index++])();
		case (3):
			(this->*f[index++])();
			break ;
	}
}