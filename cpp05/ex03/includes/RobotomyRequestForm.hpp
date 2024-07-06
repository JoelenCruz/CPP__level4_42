/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:04:52 by joe               #+#    #+#             */
/*   Updated: 2024/06/30 14:11:07 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

#include <cstdlib>	//std::rand(); std::srand()
#include <ctime>	//std::time();

#define RRF_SIGN_GRADE 72
#define RRF_EXEC_GRADE 45


class RobotomyRequestForm : public AForm
{
	public:
		/* Orthodox Canonical Form Methods */
		RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm &operator = (RobotomyRequestForm const &rhs);
		~RobotomyRequestForm(void);

		/* Member Function */
		void	execute(Bureaucrat const &executor) const;
		static AForm	*create(std::string const &target);
};