/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:00:00 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/07/15 19:00:01 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
 
#define RESET_COLOR "\033[0m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define PINK "\033[35m"

#define PRINT_COLOR(color, message) std::cout << color << message << RESET_COLOR << std::endl;

#include <string>
#include <stack>
#include <sstream>
#include <iostream>
#include <cstdlib>


class RPN 
{
    private:
	    std::stack<char> _stack;

        void initStack(std::string expression);
        bool isZero(const std::string &input);
        void operations(const std::string &token, std::stack<int> &stack);
        bool isOperator(const std::string &token);
    
    public:
        /* Orthodox Canonical methods */
        RPN(void);
        RPN(RPN const &sr);
        ~RPN(void);
        RPN &operator = (RPN const &rhs);

        /* Functions */
        void calculate(const std::string &input);

        


        class DivisionByZero : public std::exception
        {
            public:
            const char * what() const throw();
        };

        class NotEnoughOperands : public std::exception
        {
            public:
            const char * what() const throw();
        };

        class IvalidInput : public std::exception
        {
            public:
            const char * what() const throw();
        };

        class TooManyOperands : public std::exception
        {
            public:
            const char * what() const throw();
        };
};