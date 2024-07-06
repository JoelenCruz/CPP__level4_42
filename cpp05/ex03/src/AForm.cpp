/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:20:53 by joe               #+#    #+#             */
/*   Updated: 2024/06/30 14:59:16 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"


// =============================================================================
// EXCPTIONS
// =============================================================================



const char	*AForm::FormDoesntExist::what(void) const throw()
{
	PRINT_COLOR(YELLOW,"⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️");
	PRINT_COLOR(YELLOW,"Exception: Form Doesnt Exist!");
    PRINT_COLOR(YELLOW,"⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️");

	return "";
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	PRINT_COLOR(YELLOW,"⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️");
	PRINT_COLOR(YELLOW,"Exception: Form's grade is too high!");
    PRINT_COLOR(YELLOW,"⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️");

	return "";
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	PRINT_COLOR(YELLOW,"⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️");
	PRINT_COLOR(YELLOW,"Exception: Form's grade is too low!");
    PRINT_COLOR(YELLOW,"⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️");

	return "";
}

const char	*AForm::FormNotSignedException::what(void) const throw()
{
	PRINT_COLOR(YELLOW,"⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️");
	PRINT_COLOR(YELLOW,"Exception: Form not sigend!");
    PRINT_COLOR(YELLOW,"⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️");

	return "";
}

// =============================================================================
// CONSTRUCTORS AND DESTRUCTOR
// =============================================================================

AForm::AForm(): 
	_name("None"),
	_signed(false),
	_gradeSign(MAX_GRADE), 
	_gradeExecute(MAX_GRADE),
	_target("None")
{
	PRINT_COLOR(BLUE, "A📝 Default Form constructor!");
	PRINT_COLOR(BLUE, _name);
}


AForm::AForm(std::string const &name, int const &gradeSign, int const &gradeExecute): 
		
		_name(name), 
		_gradeSign(gradeSign),
		_gradeExecute(gradeExecute)
		
{
	this->_signed = false;
	if (this->getGradeSign() > MAX_GRADE || this->getGradeExec() > MAX_GRADE)
		throw AForm::GradeTooLowException();
	if (this->getGradeSign() < MIN_GRADE || this->getGradeExec() < MIN_GRADE)
		throw AForm::GradeTooHighException();
		
	PRINT_COLOR(BLUE, "A📝 Parameter Form constructor!");
    PRINT_COLOR(BLUE, name);
}


AForm::AForm(AForm const &src) : 
	_gradeSign(src.getGradeSign()), 
	_gradeExecute(src.getGradeExec())
{
	const_cast<std::string &>(this->_name) = src.getName();
	this->_signed = src.getSigned();
	const_cast<std::string &>(this->_target) = src.getTarget();
	return ;
	PRINT_COLOR(BLUE, "A📝 Copy Constructor called");
}


AForm::~AForm(void)
{
	PRINT_COLOR(RED , "A📝  Destructor called");
}

// =============================================================================
// OPERATOR OVERLOAD
// =============================================================================

AForm & AForm::operator = (AForm const &rhs)
{
	PRINT_COLOR(BLUE, "⚙️ Assignment operator called")
	if (this != &rhs)
	{
		const_cast<std::string &>(this->_name) = rhs.getName();
		this->_signed = rhs.getSigned();
		const_cast<int &>(this->_gradeSign) = rhs.getGradeSign();
		const_cast<int &>(this->_gradeExecute) = rhs.getGradeExec();
		this->_target = rhs._target;
	}
	return (*this);
}


std::ostream &operator << (std::ostream &o, AForm const &i)
{
	(void)i;
	o << std::endl;
	o << "================> Form name: " << i.getName() << std::endl;
	o << "================> Signed: " << (i.getSigned() ? "True" : "False") << std::endl;
	o << "================> Signature Grade: " << i.getGradeSign() << std::endl;
	o << "================> Execution Grade: " << i.getGradeExec();
	return (o);
}


// =============================================================================
// Getters
// =============================================================================
std::string	AForm::getName(void) const
{
	return (this->_name);
}


bool	AForm::getSigned(void) const
{
	return (this->_signed);
}

int	AForm::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int	AForm::getGradeExec(void) const
{
	return (this->_gradeExecute);
}

std::string	AForm::getTarget(void) const
{
	return (this->_target);
}

// =============================================================================
// Setters
// =============================================================================


void	AForm::setName(std::string const name)
{
	const_cast<std::string &>(this->_name) = name;
}


void	AForm::setSign(bool const sign)
{
	const_cast<bool &>(this->_signed) = sign;
}


void	AForm::setGradeSign(int const grade)
{
	const_cast<int &>(this->_gradeSign) = grade;
}


void	AForm::setGradeExec(int const grade)
{
	const_cast<int &>(this->_gradeExecute) = grade;
}


void	AForm::setTarget(std::string const target)
{
	const_cast<std::string &>(this->_target) = target;
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeSign())
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
}