/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:04:41 by joe               #+#    #+#             */
/*   Updated: 2024/06/29 16:15:44 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

#define RESET_COLOR "\033[0m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define PINK "\033[35m"


// =============================================================================
// CLASS
// =============================================================================

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeSign;
		const int _gradeExecute;
	
	public:
		/* Orthodox Canonical Form methods */
		Form(void);
		Form(std::string const &name, int const &_gradeSign, int const &_gradeExecute);
		Form(Form const &src);
		Form &operator = (Form const &rhs);
		~Form(void);

		/* Member Functions */
		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getGradeSign(void) const;
		int			getGradeExec(void) const;
		void		beSigned(Bureaucrat &bureaucrat);
		
		class	GradeTooHighException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
		
		class	GradeTooLowException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
};

std::ostream &operator << (std::ostream &o, Form const &i);