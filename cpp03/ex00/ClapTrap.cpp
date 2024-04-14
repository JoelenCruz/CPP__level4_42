/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:03:49 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/14 17:25:01 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


#define MSG true

// *==============================================================================
// *CONSTURCTOR AND DESTRUCTOR  
// *==============================================================================

ClapTrap::ClapTrap(void): _name("Default"), _attacksPoints(10), _hitPoints(10), _damage(0)
{
    if (MSG == true)
        PRINT("🌞 ClapTrap Default constructor called");
    return;
}

ClapTrap::ClapTrap(std::string const name): _name(name), _attacksPoints(10), _hitPoints(10), _damage(0)
{
    if (MSG == true)
	    PRINT("🌞 ClapTrap String Name constructor called");
    return;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	if(MSG == true)
		PRINT("⚪ ClapTrap Copy constructor called");
	setName(src.getName());
	setHitPoints(src.getHitPoints());
	setAttacksPoints(src.getAttacksPoints());
	setDamage(src.getDamage());
	return ;
}

ClapTrap::~ClapTrap(void)
{
    if (MSG == true)
        PRINT("Default destructor called");
    return;
}


// *=============================================================================
// *OPERATORS
// *=============================================================================

ClapTrap & ClapTrap::operator = (ClapTrap const &rhs)
{
	if (MSG == true)
		PRINT("⚪ Assignment operator called");
	if (this != &rhs)
	{
		setName(rhs.getName());
		setHitPoints(rhs.getHitPoints());
		setAttacksPoints(rhs.getAttacksPoints());
		setDamage(rhs.getDamage());
	}
	return (*this);
}

// *=============================================================================
// *GETTERS
// *=============================================================================

std::string	ClapTrap::getName(void) const
{
	return (_name);
}

int	ClapTrap::getHitPoints(void) const
{
	return (_hitPoints);
}

int ClapTrap::getAttacksPoints(void) const
{
    return (_attacksPoints);    
}

int	ClapTrap::getDamage(void) const
{
	return (_damage);
}

// *=============================================================================
// *SETTERS
// *=============================================================================

void ClapTrap::setName(std::string const &name)
{
	_name = name;
}

void	ClapTrap::setHitPoints(int const hitPoints)
{
	_hitPoints = hitPoints;
}

void ClapTrap::setAttacksPoints(int const points)
{
    _attacksPoints = points;    
}

void	ClapTrap::setDamage(int const demage)
{
	_damage = demage;
}

// *==============================================================================
// *FUNCTIONS
// *==============================================================================

void ClapTrap::attack(const std::string &target)
{
    if(!getAttacksPoints())
    {
        PRINT("ClapTrap" << getName() << "🫥 no energy!")
        return;
    }
    PRINT("ClapTrap " << getName() << " attacks " << target << \
		", causing " << getDamage() << " points of damage!");
	setAttacksPoints(getAttacksPoints() - 1);
    
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!getHitPoints())
	{
		PRINT("💀 ClapTrap " << getName() << \
			" is beyond repair and can't sustain any more damage!");
		return ;
	}
	if ((unsigned int)getHitPoints() > amount)
	{
		setHitPoints(getHitPoints() - amount);
		PRINT("🔫 ClapTrap " << getName() << \
			" takes " << amount << " damage! HP: " << getHitPoints());
	}
	else
	{
		PRINT("🔫💀 ClapTrap " << getName() << \
			" takes " << getHitPoints() << " damage! HP: 0 ");
		setHitPoints(0);
	}
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!getAttacksPoints())
	{
		PRINT("🪫 ClapTrap " << getName() << \
			" doesn't have any more energy!");
		return ;
	}
	setHitPoints(getHitPoints() + amount);
	setAttacksPoints(getAttacksPoints() - 1);
	PRINT("ClapTrap " << getName() << \
			" repairs " << amount << " hitpoints! HP: " << getHitPoints());
}

std::ostream & operator << (std::ostream &o, ClapTrap const &i)
{
	o << "+---" << std::endl;
	o << "| ClapTrap" << std::endl;
	o << "| Name: " << i.getName() << std::endl;
	o << "| Hit Points: " << i.getHitPoints() << std::endl;
	o << "| Energy Points: " << i.getAttacksPoints() << std::endl;
	o << "| Attack Damage: " << i.getAttacksPoints() << std::endl;
	o << "+---" << std::endl;
	return (o);
}