/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:04:41 by joe               #+#    #+#             */
/*   Updated: 2024/06/30 14:06:13 by joe              ###   ########.fr       */
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

class AForm
{
	private:
		const std::string 	_name;
		bool 				_signed;
		const int 			_gradeSign;
		const int 			_gradeExecute;
		std::string			_target;
	
	protected:
		void	setName(std::string const name);
		void	setSign(bool const sign);
		void	setGradeSign(int const grade);
		void	setGradeExec(int const grade);
		void	setTarget(std::string const target);
		
	
	public:
		/* Orthodox Canonical Form methods */
		AForm(void);
		AForm(std::string const &name, int const &_gradeSign, int const &_gradeExecute);
		AForm(AForm const &src);
		AForm &operator = (AForm const &rhs);
		~AForm(void);

		/* Member Functions */
		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getGradeSign(void) const;
		int			getGradeExec(void) const;
		std::string	getTarget(void) const;
		void		beSigned(Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const = 0;
		
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
		class	FormNotSignedException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
};

std::ostream &operator << (std::ostream &o, AForm const &i);