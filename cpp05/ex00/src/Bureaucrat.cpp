/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:20:53 by joe               #+#    #+#             */
/*   Updated: 2024/06/24 15:12:40 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

// *=============================================================================
// *CONSTRUCTORS AND DESTRUCTOR
// *=============================================================================

Bureaucrat::Bureaucrat() : _name("bureaucrat not name"), _grade(100)
{
	PRINT_COLOR(BLUE, "👔 Bureaucrat constructor!");
	return ;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : _name(name)
{
    PRINT_COLOR(BLUE, "👔 Bureaucrat constructor!");
    PRINT_COLOR(BLUE, name);
    PRINT_COLOR(BLUE, "\n");
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& name)
{
	*this = name;
}

Bureaucrat::~Bureaucrat()
{
	PRINT_COLOR(RED,"❌👔 Bureaucrat Destructor called!");
	return ;
}

// *=============================================================================
// *OPERATORS OVERLOAD
// *=============================================================================
Bureaucrat& Bureaucrat::operator= (Bureaucrat const &rhs)
{
	const_cast<std::string&>(this->_name) = rhs._name;
	this->_grade = rhs._grade;
	return (*this);
}


// *=============================================================================
// *MEMBER FUNCTIONS
// *=============================================================================
std::string		Bureaucrat::getName(void) const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);	
}

void			Bureaucrat::incrementGrade(void)
{
	if (this->_grade == MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void			Bureaucrat::decrementGrade(void)
{
	if (this->_grade == MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what()
{
    PRINT_COLOR(YELLOW,"⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️");
	PRINT_COLOR(YELLOW,"Exception: Bureaucrat's grade is too high!");
    PRINT_COLOR(YELLOW,"⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️");
    return (0);
}

const char* Bureaucrat::GradeTooLowException::what()
{
    PRINT_COLOR(YELLOW,"⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️");
	PRINT_COLOR(YELLOW,"Exception: Bureaucrat's grade is too low!");
    PRINT_COLOR(YELLOW,"⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️");
    return (0);
}

std::ostream& operator <<(std::ostream &out, const Bureaucrat& bureaucrat)
{
    PRINT_COLOR(GREEN, "Bureaucrat: ")
    PRINT_COLOR(GREEN,  bureaucrat.getName())
    PRINT_COLOR(GREEN, "⬇⬇️")
    PRINT_COLOR(GREEN,  bureaucrat.getGrade())
    PRINT_COLOR(GREEN, "--------------------------------------")
	return (out);
}