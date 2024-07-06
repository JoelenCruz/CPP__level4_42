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

#pragma once

// =============================================================================
// Includes
// =============================================================================

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

// =============================================================================
// Class
// =============================================================================

class Intern
{
	public:
		/* Orthodox Canonical Form Methods */
		Intern(void);
		Intern(Intern const &src);
		Intern & operator = (Intern const &rhs);
		~Intern(void);

		AForm* makeForm(std::string form_name, std::string form_target);
		AForm* makePresidentialForm(const std::string target);
		AForm* makeRobotomyForm(const std::string target);
		AForm* makeShrubberyForm(const std::string target);
};