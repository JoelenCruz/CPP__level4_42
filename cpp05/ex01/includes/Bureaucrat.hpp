/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:04:41 by joe               #+#    #+#             */
/*   Updated: 2024/06/29 16:15:58 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "Form.hpp"

#define RESET_COLOR "\033[0m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define PINK "\033[35m"

#define	MAX_GRADE 150
#define	MIN_GRADE 1

#define PRINT_COLOR(color, message) std::cout << color << message << RESET_COLOR << std::endl;

#define ERROR(x) std::cerr << x << std::endl;

// =============================================================================
// CLASS
// =============================================================================

class Form;

class Bureaucrat
{
	private:
		std::string const	_name;
		int		_grade;
	
	public:
		/* Orthodox Canonical Form methods */
		Bureaucrat(void);
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat &operator = (Bureaucrat const &rhs);
		~Bureaucrat(void);

		/* Member Functions */
		int	getGrade(void) const;
		std::string		getName(void) const;
		void			decrementGrade(void);
		void			incrementGrade(void);
		void			signForm(Form &form);

		
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

std::ostream &operator << (std::ostream &o, Bureaucrat const &i);