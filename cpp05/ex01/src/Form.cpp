/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:20:53 by joe               #+#    #+#             */
/*   Updated: 2024/06/29 17:03:30 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"


// =============================================================================
// EXCPTIONS
// =============================================================================

const char	*Form::GradeTooHighException::what(void) const throw()
{
	PRINT_COLOR(YELLOW,"⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️");
	PRINT_COLOR(YELLOW,"Exception: Form's grade is too high!");
    PRINT_COLOR(YELLOW,"⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️");

	return "";
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	PRINT_COLOR(YELLOW,"⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️");
	PRINT_COLOR(YELLOW,"Exception: Form's grade is too low!");
    PRINT_COLOR(YELLOW,"⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️");

	return "";
}

// =============================================================================
// CONSTRUCTORS AND DESTRUCTOR
// =============================================================================


Form::Form(): _name("Some form"), _signed(false), _gradeSign(MAX_GRADE), _gradeExecute(MAX_GRADE)
{
	PRINT_COLOR(BLUE, "📝 Default Form constructor!");
	PRINT_COLOR(BLUE, _name);
}


Form::Form(std::string const &name, int const &gradeSign, int const &gradeExecute): 
		
		_name(name), 
		_signed (false),
		_gradeSign(gradeSign),
		_gradeExecute(gradeExecute)
		
{
	if (gradeSign < MIN_GRADE || gradeExecute < MIN_GRADE )
		throw	Form::GradeTooHighException();
	if (gradeExecute > MAX_GRADE || gradeSign > MAX_GRADE)
		throw	Form::GradeTooLowException();
		
	PRINT_COLOR(BLUE, "📝 Parameter Form constructor!");
    PRINT_COLOR(BLUE, name);
	
}


Form::Form(Form const &src): 
		_name(src.getName()), 
		_signed(src.getSigned()),
		_gradeSign(src.getGradeSign()), 
		_gradeExecute(src.getGradeExec())
{
	PRINT_COLOR(BLUE, "📝 Copy Constructor called");
}


Form::~Form(void)
{
	PRINT_COLOR(RED , "📝  Destructor called");
}

// =============================================================================
// OPERATOR OVERLOAD
// =============================================================================

Form & Form::operator = (Form const &rhs)
{
	PRINT_COLOR(BLUE, "⚙️ Assignment operator called")
	if (this != &rhs)
	{
		const_cast<std::string &>(this->_name) = rhs.getName();
		this->_signed = rhs.getSigned();
		const_cast<int &>(this->_gradeSign) = rhs.getGradeSign();
		const_cast<int &>(this->_gradeExecute) = rhs.getGradeExec();
	}
	return (*this);
}


std::ostream &operator << (std::ostream &o, Form const &i)
{
	(void)i;
	o << std::endl;
	o << "================> Form name: " << i.getName() << std::endl;
	o << "================> Signed: " << (i.getSigned() ? "True" : "False") << std::endl;
	o << "================> Grade required to execute: " << i.getGradeExec() << std::endl;
	o << "================> Grade required to sign: " << i.getGradeSign() << std::endl;
	return (o);
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

std::string	Form::getName(void) const
{
	return (this->_name);
}


bool	Form::getSigned(void) const
{
	return (this->_signed);
}

int	Form::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int	Form::getGradeExec(void) const
{
	return (this->_gradeExecute);
}


void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeSign())
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}