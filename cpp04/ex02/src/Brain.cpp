/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:41:56 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/04/21 16:41:58 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#define MSG true

// *=============================================================================
// *CONSTRUCTORS AND DESTRUCTOR
// *=============================================================================

Brain::Brain(void)
{
    if(MSG == true)
        PRINT("🧠 Brain: construct!");
    std::string ideas[IDEAS] = 
    {
        "ideia_0","ideia_1", "ideia_2", 
        "ideia_3",
        "ideia_4", "ideia_5", "ideia_6",
        "ideia_7", "ideia_8", "ideia_9",
        "ideia_10", "ideia_11", "ideia_12",
        "ideia_13", "ideia_14", "ideia_15",
        "ideia_16", "ideia_17", "ideia_18",
        "ideia_19", "ideia_20", "ideia_21",
        "ideia_22", "ideia_23", "ideia_24",
        "ideia_25", "ideia_26", "ideia_27",
        "ideia_28", "ideia_29", "ideia_30",
        "ideia_31", "ideia_32", "ideia_33",
        "ideia_34", "ideia_35", "ideia_36",
        "ideia_37", "ideia_38", "ideia_39",
        "ideia_40", "ideia_41", "ideia_42",
        "ideia_43", "ideia_44", "ideia_45",
        "ideia_46", "ideia_47", "ideia_48",
        "ideia_49", "ideia_50", "ideia_51",
        "ideia_52", "ideia_53", "ideia_54",
        "ideia_55", "ideia_56", "ideia_57",
        "ideia_58", "ideia_59", "ideia_60",
        "ideia_61", "ideia_62", "ideia_63",
        "ideia_64", "ideia_65", "ideia_66",
        "ideia_67", "ideia_68", "ideia_69",
        "ideia_70", "ideia_71", "ideia_72",
        "ideia_73", "ideia_74", "ideia_75",
        "ideia_76", "ideia_77", "ideia_78",
        "ideia_79", "ideia_80", "ideia_81",
        "ideia_82", "ideia_83", "ideia_84",
        "ideia_85", "ideia_86", "ideia_87",
        "ideia_88", "ideia_89", "ideia_90",
        "ideia_91", "ideia_92", "ideia_93",
        "ideia_94", "ideia_95", "ideia_96",
        "ideia_97", "ideia_98", "ideia_99",
    };
    for (size_t i = 0; i < IDEAS; i++)
		this->_ideas[i] = ideas[i];
    return ;
}

Brain::Brain(Brain const &src)
{
    if(MSG == true)
        PRINT("🧠 Brain: copy constructor!");
    for (size_t i = 0; i < IDEAS; i++)
		this->_ideas[i] = src._ideas[i];
	return ;

}

Brain::~Brain(void)
{
	if (MSG == true)
		PRINT("❌🧠  Brain: Destructor called");
    return ;
}


// *=============================================================================
// *OPERATORS
// *=============================================================================

Brain & Brain::operator= (Brain const &rhs) 
{
    if(MSG == true)
        PRINT("🧠 Assignment operator called");
    if (this != &rhs)
        for (size_t i = 0; i < IDEAS; i++)
            this->_ideas[i] = rhs._ideas[i];
    return (*this);
}

// *=============================================================================
// *MEMBER FUNCTIONS
// *=============================================================================

std::string	Brain::getIdea(size_t i) const
{
	return (this->_ideas[i]);
}

void	Brain::setIdea(size_t i, std::string idea)
{
	this->_ideas[i] = idea;
}