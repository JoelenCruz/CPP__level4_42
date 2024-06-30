/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:08:50 by joe               #+#    #+#             */
/*   Updated: 2024/06/30 14:09:40 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


// =============================================================================
// Constructor and Destructor
// =============================================================================

PresidentialPardonForm::PresidentialPardonForm(): 
    AForm("Presidential Pardon Form", PPF_SIGN, PPF_EXEC)
{
    PRINT_COLOR(BLUE,"👨‍💼📄 Default Constructor called");
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src)
{
	this->setName(src.getName());
	this->setSign(src.getSigned());
	this->setGradeSign(src.getGradeSign());
	this->setGradeExec(src.getGradeExec());
	this->setTarget(src.getTarget());
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
	AForm("Presidential Pardon Form", PPF_SIGN, PPF_EXEC)
{
	PRINT_COLOR(BLUE, "👨‍💼📄 Parameter Constructor called");
	this->setTarget(target);
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	PRINT_COLOR(BLUE,"👨‍💼📄 Destructor called");
	return ;
}

// =============================================================================
// Operator Overload
// =============================================================================

PresidentialPardonForm &PresidentialPardonForm::operator = (PresidentialPardonForm const &rhs)
{

	PRINT_COLOR(BLUE,"👨‍💼📄 Assignment operator called");
	if (this != &rhs)
	{
		this->setName(rhs.getName());
		this->setSign(rhs.getSigned());
		this->setGradeSign(rhs.getGradeSign());
		this->setGradeExec(rhs.getGradeExec());
		this->setSign(rhs.getSigned());
	}
	return (*this);
}

// =============================================================================
// Member Function
// =============================================================================

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
    PRINT_COLOR(BLUE, "has been pardoned by Zaphod Beeblebrox");
}
