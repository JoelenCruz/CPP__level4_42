/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:03:46 by joe               #+#    #+#             */
/*   Updated: 2024/06/30 13:17:02 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

#define PPF_SIGN 25
#define PPF_EXEC 5


class PresidentialPardonForm : public AForm
{
	public:
		/* Orthodox Canonical Form Methods */
		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm &operator = (PresidentialPardonForm const &rhs);
		~PresidentialPardonForm(void);

		/* Member Functions */
		void	execute(Bureaucrat const &executor) const;
};