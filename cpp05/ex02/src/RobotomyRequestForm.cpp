/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:15:21 by joe               #+#    #+#             */
/*   Updated: 2024/06/30 14:37:07 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"


// =============================================================================
// Constructor and Destructor
// =============================================================================

RobotomyRequestForm::RobotomyRequestForm(): 
    AForm("Robotomy Request Form", RRF_SIGN_GRADE, RRF_EXEC_GRADE)
{
    PRINT_COLOR(BLUE,"🤖📄 Default Constructor called");
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src)
{
	this->setName(src.getName());
	this->setSign(src.getSigned());
	this->setGradeSign(src.getGradeSign());
	this->setGradeExec(src.getGradeExec());
	this->setTarget(src.getTarget());
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
	AForm("Robotomy Request Form", RRF_SIGN_GRADE, RRF_EXEC_GRADE)
{
	PRINT_COLOR(BLUE, "🤖📄 Parameter Constructor called");
	this->setTarget(target);
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	PRINT_COLOR(BLUE,"🤖📄 Destructor called");
	return ;
}

// =============================================================================
// Operator Overload
// =============================================================================

RobotomyRequestForm &RobotomyRequestForm::operator = (RobotomyRequestForm const &rhs)
{

	PRINT_COLOR(BLUE,"🤖📄 Assignment operator called");
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
// Member Functions
// =============================================================================

/**
 * @brief When the executor have the required grades, make some drilling noises.
 * Then informs that the '_target' has been robotomized successfully 50% of 
 * time. Otherwise, informs that he robotomy failed.
 * 
 * @param executor A Bureaucrat object.
 */
void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	PRINT_COLOR(BLUE, "* some drilling noise *");
	std::srand(std::time(0));
	if (std::rand() % 2)
	{
		PRINT_COLOR(BLUE,this->getTarget());
		PRINT_COLOR(BLUE,"has been robotomized successfully.");
	}
	else
	{
		PRINT_COLOR(BLUE,"Robotomization failed on ")
		PRINT_COLOR(BLUE,this->getTarget());
	}
}