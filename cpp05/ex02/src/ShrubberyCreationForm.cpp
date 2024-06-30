/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:42:39 by harndt            #+#    #+#             */
/*   Updated: 2024/06/30 15:18:03 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// =============================================================================
// Exceptions
// =============================================================================

const char	*ShrubberyCreationForm::FileCreateErrorException::what(void) const throw()
{

	PRINT_COLOR(YELLOW,"⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️");
	PRINT_COLOR(YELLOW,"Exception: Error, file not created.");
    PRINT_COLOR(YELLOW,"⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️");

	return "";
}


// =============================================================================
// Constructor and Destructor
// =============================================================================

ShrubberyCreationForm::ShrubberyCreationForm(): 
    AForm("Shrubbery Creation Form", SCF_SIGN_GRADE, SCF_EXEC_GRADE)
{
    PRINT_COLOR(BLUE,"🌳📄 Default Constructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src)
{
	this->setName(src.getName());
	this->setSign(src.getSigned());
	this->setGradeSign(src.getGradeSign());
	this->setGradeExec(src.getGradeExec());
	this->setTarget(src.getTarget());

	PRINT_COLOR(GREEN, "🌳📄 Copy Constructor called");
	
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :
	AForm("Shrubbery Creation Form", SCF_SIGN_GRADE, SCF_EXEC_GRADE)
{
	PRINT_COLOR(BLUE, "🌳📄 Parameter Constructor called");
	this->setTarget(target);
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	PRINT_COLOR(BLUE,"🌳📄 Destructor called");
	return ;
}

// =============================================================================
// Operator Overload
// =============================================================================

ShrubberyCreationForm &ShrubberyCreationForm::operator = (ShrubberyCreationForm const &rhs)
{

	PRINT_COLOR(BLUE,"🌳📄 Assignment operator called");
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
 * @brief When the executor have the required grades, creates a file with and
 * writes an ASCII tree inside it.
 * 
 * @param executor A Bureaucrat object.
 */
void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string		filename;
	std::ofstream	outfile;
	AForm::execute(executor);

	filename = this->getTarget() + "_shrubbery";
	std::ofstream out(filename.c_str());
	if (!out.is_open() || out.fail())
		throw ShrubberyCreationForm::FileCreateErrorException();
	outfile.open(filename.c_str());
	outfile << SHRUBBERY;
	PRINT_COLOR(RED, filename);
	PRINT_COLOR(RED, "created with success");
	outfile.close();
	out.close();
}