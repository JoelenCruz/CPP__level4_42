/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:47:58 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/07/16 00:30:34 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

// =============================================================================
// Exceptions
// =============================================================================

const char * RPN::DivisionByZero::what() const throw()
{
	PRINT_COLOR(RED, "Error: division by zero.");
	 return"";
}

const char * RPN::NotEnoughOperands::what() const throw()
{
	PRINT_COLOR(RED, "Error: not enough operands.");
	 return"";
}

const char * RPN::IvalidInput::what() const throw()
{
	PRINT_COLOR(RED, "Error: invalid input");
	 return"";
}

const char * RPN::TooManyOperands::what() const throw()
{
	PRINT_COLOR(RED, "Error: too many operands.");
	 return"";
}







// =============================================================================
// Constructors and Destructor
// =============================================================================

RPN::RPN(void){}

RPN::RPN(RPN const &src)
{
	(void)src;
}

RPN::~RPN(void)
{
    
}

// =============================================================================
// Operator Overload
// =============================================================================



RPN & RPN::operator = (RPN const &rhs){
	(void)rhs;
	return (*this);
}

bool RPN::isZero(const std::string &input) 
{
    if(input.size() == 1 && (input[0]) == '0')
        return true;
    return false;
}

bool RPN::isOperator(const std::string &token) 
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

void RPN::operations(const std::string &token, std::stack<int> &stack) 
{
    try
    {
        if (stack.size() < 2) 
            throw NotEnoughOperands();

        int operand2 = stack.top();
        stack.pop();
        int operand1 = stack.top();
        stack.pop();
        
        if (token == "+")
            stack.push(operand1 + operand2);
        else if (token == "-") 
            stack.push(operand1 - operand2);
        else if (token == "*")
            stack.push(operand1 * operand2);
        else if (token == "/") 
        {
            if (operand2 == 0) 
                throw DivisionByZero();
            stack.push(operand1 / operand2);
        }
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        std::exit(EXIT_FAILURE);
    }  
}


void RPN::calculate(const std::string &input) 
{
    std::stack<int> stack;
    std::istringstream iss(input);
    std::string token;
    int i = 0;

    while (iss >> token) 
    {
        if(isZero(token)) 
                stack.push(0);
        else
        {
            try
            {
                int number = std::atoi(token.c_str());   
                // PRINT_COLOR(RED, token << " volta: " << i);
                if (isOperator(token))
                    operations(token, stack);
                else if (number == 0) //Erro do Atoi --1, ++1
                {
                    throw IvalidInput();
                }
                    
                else if (number >= -9 && number <= 9)
                        stack.push(number);
                else 
                    throw IvalidInput();
                i++;
            }
            catch(const std::exception& e){
                std::cerr << e.what() << '\n';
                std::exit(EXIT_FAILURE);
            }
        }
        
    }

    try
    {
        if (stack.size() != 1) 
            throw TooManyOperands();
        else if (stack.size() == 1 && i == 1)
            throw NotEnoughOperands();
    
        else if(stack.size() == 1 && i >= 3)
            PRINT_COLOR(GREEN, "Result: " << stack.top());
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        std::exit(EXIT_FAILURE);
    }
}   


