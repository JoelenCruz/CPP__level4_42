/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:05:30 by joe               #+#    #+#             */
/*   Updated: 2024/06/30 14:30:11 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

#include <fstream>

#define SCF_SIGN_GRADE 145
#define SCF_EXEC_GRADE 137

#define SHRUBBERY \
"\
                 		 mmmmmmmm                \n\
                        mmmmmmmmmmmmmm            \n\
          mmmmmmmmmm    mmmmmmmmmmmmmmmmmm        \n\
          mmmmmmmmmmmm  mmmmmmmmmmmmmmmmmmmm      \n\
        mmmmmmmmmmmmmm  mmmmmmmmmmmmmmmmmmmm      \n\
      mmmmmmmmmmmmmmmmmm  mmmmmmmmmmmmmmmmmm      \n\
    mmmmmmmmmmmmmmmmmmmm  mmmmmmmmmmmmmmmm        \n\
    mmmmmmmmmmmmmmmmmmmm  mmmmmmmmmm              \n\
    mmmmmmmmmmmmmmmmmmmmmm          mmmm          \n\
      mmmmmmmmmmmmmm      O    mmmmmmmmmmmmmmmm    \n\
                      mmmm    mmmmmmmmmmmmmmmmmm  \n\
                mmmmmmmmmmmm  mmmmmmmmmmmmmmmmmm  \n\
            mmmmmmmmmmmmmmmm    mmmmmmmmmmmmmmmm  \n\
          mmmmmmmmmmmmmmmmmmmm  mmmmmmmmmmmmmm    \n\
          mmmmmmmmmmmmmmmmmmmm  mmmmmmmmmmmmmm    \n\
        mmmmmmmmmmmmmmmmmmmmmm  mmmmmmmmmmmmmm    \n\
        mmmmmmmmmmmmmmmmmmmmmm    mmmmmmmmmmmm    \n\
          mmmmmmmmmmmmmmmmmmmm      mmmmmmmm      \n\
            mmmmmmmmmmmmmmmm  		  mmmm         \n\
                  mmmmmmmm                   \n\
                    mmmm                    \n\
"              

// =============================================================================
// Class
// =============================================================================

class ShrubberyCreationForm : public AForm
{
	public:
		/* Orthodox Canonical Form Methods */
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm &operator = (ShrubberyCreationForm const &rhs);
		~ShrubberyCreationForm(void);

		/* Throw Exceptions */
		class	FileCreateErrorException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};

		/* Member Functions */
		void	execute(Bureaucrat const &executor) const;
		static AForm	*create(std::string const &target);
};