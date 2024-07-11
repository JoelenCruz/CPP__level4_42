/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:59:23 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/07/08 20:09:22 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ScalarConverter.hpp"

int	subject_tests (void)
{
	const char*        char_tests[] = {"c", "#",  "", "-", "+","oi", NULL };
	const char*        int_tests[] = {"2147483648", "-2147483649", "42", "0", "-0", "+10", "127", "899", NULL };
	const char*        float_tests[] = {"-4.2f", "nanf", "-inff", "+inff", "1...0f", NULL };
	const char*        double_tests[] = {"1.1426576", "0.57463824344","4.2", "-4.2", "nan", "-inf", "+inf", "45.88", "1...0f", NULL };

	PRINT_COLOR(YELLOW, "----------CHAR TESTS----------");
	for (int i = 0; char_tests[i]; i++)
	{
		std::cout << "[" << char_tests[i] << "]\n";
		try
		{
			ScalarConverter::convert(char_tests[i]);
		}
		catch ( ScalarConverter::UnknownTypeException& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n\n";
	}

	PRINT_COLOR(YELLOW,"----------INT TESTS----------");
	for (int i = 0; int_tests[i]; i++)
	{
		std::cout << "[" << int_tests[i] << "]\n";
		try
		{
			ScalarConverter::convert(int_tests[i]);
		}
		catch ( ScalarConverter::UnknownTypeException& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n\n";
	}

	PRINT_COLOR(YELLOW,"----------FLOAT TESTS----------")
	for (int i = 0; float_tests[i]; i++)
	{
		std::cout << "[" << float_tests[i] << "]\n";
		try
		{
			ScalarConverter::convert(float_tests[i]);
		}
		catch ( ScalarConverter::UnknownTypeException& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n\n";
	}

	PRINT_COLOR(YELLOW,"----------DOUBLE TESTS----------")
	for (int i = 0; double_tests[i]; i++)
	{
		std::cout << "[" << double_tests[i] << "]\n";
		try
		{
			ScalarConverter::convert(double_tests[i]);
		}
		catch ( ScalarConverter::UnknownTypeException& e)
		{
			std::cout << e.what();
		}
		std::cout << "\n\n";
	}
	return (0);
}

int menu() {
    PRINT_COLOR(PINK, "\n---------------------------------------------");
    PRINT_COLOR(PINK, "Escolha um teste para rodar:");
    PRINT_COLOR(PINK, "[1] Teste 1: subject tests");
    PRINT_COLOR(PINK, "[2] Teste 2: input tests");
    PRINT_COLOR(PINK, "[0] End programa");
    PRINT_COLOR(PINK, "\n---------------------------------------------");

    int userInput;
    PRINT_COLOR(PINK,"Choice a number: ");
    std::cin >> userInput;

    return userInput;
}

int main() 
{
    int choice = -1;
    
    while (choice != 0) 
	{
        choice = menu();

        if (choice == 1) 
            subject_tests();
		else if (choice == 2) 
		{
            std::string input;
            PRINT_COLOR(PINK, "Enter a value to convert: ");
            std::cin >> input;
            ScalarConverter::convert(input);
        } 
		else if (choice == 0)
		{
           PRINT_COLOR(RED, "End prog...");
        } 
		else 
		{
           PRINT_COLOR(RED, "Invalid choice. ");
        }
    }
    return 0;
}
