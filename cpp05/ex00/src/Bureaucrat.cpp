/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:20:53 by joe               #+#    #+#             */
/*   Updated: 2024/06/25 19:41:02 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"


// =============================================================================
// EXCPTIONS
// =============================================================================

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	PRINT_COLOR(YELLOW,"⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️");
	PRINT_COLOR(YELLOW,"Exception: Bureaucrat's grade is too high!");
    PRINT_COLOR(YELLOW,"⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️");

	return "";
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	PRINT_COLOR(YELLOW,"⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️");
	PRINT_COLOR(YELLOW,"Exception: Bureaucrat's grade is too low!");
    PRINT_COLOR(YELLOW,"⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️");

	return "";
}

// =============================================================================
// CONSTRUCTORS AND DESTRUCTOR
// =============================================================================


Bureaucrat::Bureaucrat(void)
{
	PRINT_COLOR(BLUE, "👔 Default Bureaucrat constructor!");
	const_cast<std::string &>(this->_name) = "Undefined";
	/*
	How to cast const?
	
	const_cast<char *>(x)
	Const casts look like regular typecasts in C++, except that they can only 
	be used for casting away constness (or volatile-ness) but not converting 
	between types or casting down a class hierarchy. 

	https://www.cprogramming.com/tutorial/const_correctness.html
	https://en.cppreference.com/w/cpp/language/const_cast
	*/
	this->_grade = MAX_GRADE;
	return ;
}


Bureaucrat::Bureaucrat(std::string const &name, int grade)
{
	const_cast<std::string &>(this->_name) = name;
	if (grade < MIN_GRADE)
		throw	Bureaucrat::GradeTooHighException();
	else if (grade > MAX_GRADE)
		throw	Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	
	PRINT_COLOR(BLUE, "👔 Parameter Bureaucrat constructor!");
    PRINT_COLOR(BLUE, name);

	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	PRINT_COLOR(BLUE, "👔 Copy Constructor called");
	const_cast<std::string &>(this->_name) = src.getName();
	this->_grade = src.getGrade();
	return ;
}


Bureaucrat::~Bureaucrat(void)
{
	PRINT_COLOR(RED , "👔  Destructor called");
	return ;
}

// =============================================================================
// OPERATOR OVERLOAD
// =============================================================================


Bureaucrat & Bureaucrat::operator = (Bureaucrat const &rhs)
{
	PRINT_COLOR(BLUE, "⚙️ Assignment operator called")
	if (this != &rhs)
	{
		const_cast<std::string &>(this->_name) = rhs.getName();
		this->_grade = rhs.getGrade();
	}
	return (*this);
}


std::ostream &operator << (std::ostream &o, Bureaucrat const &i)
{
	(void)i;
	o << std::endl;
	o << "================> Name: " << i.getName() <<std::endl;
	o << "================> Grade: " << i.getGrade() << std::endl << std::endl;
	return (o);
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================


int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}


std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}


void	Bureaucrat::decrementGrade(void)
{
	if (this->getGrade() == MAX_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}


void	Bureaucrat::incrementGrade(void)
{
	if (this->getGrade() == MIN_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}