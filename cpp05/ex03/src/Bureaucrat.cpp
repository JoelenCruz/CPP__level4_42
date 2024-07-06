/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:20:53 by joe               #+#    #+#             */
/*   Updated: 2024/06/30 15:03:25 by joe              ###   ########.fr       */
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


Bureaucrat::Bureaucrat(): _name("Some bureaucrat"), _grade(MAX_GRADE)
{
	PRINT_COLOR(BLUE, "👔 Default Bureaucrat constructor!");
	PRINT_COLOR(BLUE, _name);
}


Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name)
{
	if (grade < MIN_GRADE)
		throw	Bureaucrat::GradeTooHighException();
	else if (grade > MAX_GRADE)
		throw	Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	PRINT_COLOR(BLUE, "👔 Parameter Bureaucrat constructor!");
    PRINT_COLOR(BLUE, name);
}


Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	PRINT_COLOR(BLUE, "👔 Copy Constructor called");
	*this = src;
}


Bureaucrat::~Bureaucrat(void)
{
	PRINT_COLOR(RED , "👔  Destructor called");
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
	o << "================> Name: " << i.getName() << std::endl;
	o << "================> Grade: " << i.getGrade() << std::endl;
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


void Bureaucrat::signForm(AForm &form)
{
	if (form.getSigned())
		return ;
		
	try
	{
		form.beSigned(*this);
		PRINT_COLOR(YELLOW, this->getName());
		PRINT_COLOR(YELLOW,"SIGNED");
		PRINT_COLOR(YELLOW, form.getName());
	}
	catch(AForm::GradeTooLowException &e)
	{
		ERROR(this->getName() << " couldn't sign " << form.getName() << " because " << "\n" << e.what() << "." );
	}
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		PRINT_COLOR(BLUE, "executed");
		PRINT_COLOR(BLUE, form.getName());
	}
	catch (AForm::GradeTooLowException &e)
	{
		PRINT_COLOR(BLUE, "couldn't execute");
		PRINT_COLOR(BLUE, form.getName());
		std::cout << e.what();
	}
}

// void Bureaucrat::executeForm(AForm const &form) const
// {
// 	try
// 	{
// 		form.execute(*this);
// 		PRINT_COLOR(BLUE, "executed");
// 		PRINT_COLOR(BLUE, form.getName());
// 	}
// 	catch (AForm::FormNotSignedException &e)
// 	{
// 		PRINT_COLOR(RED, "couldn't execute because form is not signed");
// 		PRINT_COLOR(RED, form.getName());
// 		std::cout << e.what();
// 	}
// 	catch (AForm::GradeTooLowException &e)
// 	{
// 		PRINT_COLOR(RED, "couldn't execute due to grade too low");
// 		PRINT_COLOR(RED, form.getName());
// 		std::cout << e.what();
// 	}
// }