/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:04:41 by joe               #+#    #+#             */
/*   Updated: 2024/06/24 15:59:47 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <limits> // Para std::numeric_limits

#define RESET_COLOR "\033[0m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"

#define	MAX_GRADE 1
#define	MIN_GRADE 150

#define PRINT_COLOR(color, message) std::cout << color << message << RESET_COLOR << std::endl;

#define ERROR(x) std::cerr << x << std::endl;

class Bureaucrat
{
    protected:
        std::string _name;
        unsigned int _grade;
    
    public:
        /* Orthodox Canonical Form methods */
        Bureaucrat(void);
        Bureaucrat(const std::string name, unsigned int grade);
	    Bureaucrat(Bureaucrat const &src);
	    ~Bureaucrat(void);

        /* Member Functions */
        Bureaucrat &operator = (Bureaucrat const  &name);
        unsigned int	getGrade(void) const;
		std::string		getName(void) const;
		void			decrementGrade(void);
		void			incrementGrade(void);

        class GradeTooHighException : public std::exception
        {
            public:
            const char* what();
        };

	    class GradeTooLowException : public std::exception
        {
            public:
            const char* what();
        };        
};
std::ostream &operator << (std::ostream &out, Bureaucrat const &i);