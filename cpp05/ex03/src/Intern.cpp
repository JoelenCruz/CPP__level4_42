/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:03:46 by joe               #+#    #+#             */
/*   Updated: 2024/07/06 13:17:02 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// =============================================================================
// Constructors and Destructor
// =============================================================================

Intern::Intern(void)
{
	PRINT_COLOR(BLUE,"🧑‍🎓 Default Constructor called");
}

Intern::Intern(Intern const &src)
{
	PRINT_COLOR(BLUE,"🧑‍🎓 Default Constructor called");
	(void)src;
}

Intern & Intern::operator = (Intern const &rhs)
{
	PRINT_COLOR(BLUE,"🧑‍🎓 Assignment operator called");
	(void)rhs;
	return (*this);
}

Intern::~Intern(void)
{
	PRINT_COLOR(BLUE,"🧑‍🎓 Destructor called");
}

// =============================================================================
// Member Functions
// =============================================================================

/**
 * @brief It takes two strings to create an AForm.
 * 
 * @param formName The name of the AForm to be created.
 * @param target The target of the AForm to be created.
 * @return AForm* The created AForm.
 */
AForm *Intern::makeForm(std::string formName, std::string target)
{
	t_form	form = NULL;
	
	static	s_form formOptions[3] = 
	{
		{"shrubbery creation", &ShrubberyCreationForm::create},
		{"robotomy request", &RobotomyRequestForm::create},
		{"presidential pardon", &PresidentialPardonForm::create},
	};

	for (int i = 0; i < 3; i++)
	{
		if (formOptions[i].name == formName)
		{
			form = formOptions[i].form;
			break ;
		}
	}

	if (!form)
		throw AForm::FormDoesntExist();

	PRINT_COLOR(BLUE, "🧑‍🎓 Forms Created ");
    PRINT_COLOR(BLUE, formName); 
	return (form(target));
}


