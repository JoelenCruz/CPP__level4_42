/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:59:06 by joe               #+#    #+#             */
/*   Updated: 2024/07/11 20:47:30 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"
#include <iostream>

int main(void)
{
	PRINT_COLOR(YELLOW, "----------TEST 01: OUT OF BOUNDS----------")
	try
	{
		Array<std::string> TestArray;
		PRINT_COLOR(BLUE, "TestArray size = " << TestArray.size())
		PRINT_COLOR(BLUE,TestArray[0])
	}
	catch (Array<std::string>::OutOfBoundsException& e)
	{
		PRINT_COLOR(RED,e.what())
	}


	PRINT_COLOR(YELLOW, "----------TEST 02: CORRECT INDEX----------");
	try
	{
		Array<std::string> TestArray(1);
		TestArray[0] = "joe";
		PRINT_COLOR(BLUE, "TestArray size = " << TestArray.size());
		PRINT_COLOR(BLUE, "TestArray[0] = " << TestArray[0]);
	}
	catch (Array<std::string>::OutOfBoundsException& e)
	{
		PRINT_COLOR(RED,e.what())
	}
	

	
	PRINT_COLOR(YELLOW,"----------TEST 03: CORRECT INDEX CONST ARRAY----------");
	try
	{
		Array<const std::string> TestArray(1);
		// TestArray[0] = "joe"; // not compile
		PRINT_COLOR(BLUE, "TestArray size = " << TestArray.size())
		PRINT_COLOR(BLUE,"TestArray[0] = [" << TestArray[0] << "]\n")
	}
	catch (Array<std::string>::OutOfBoundsException& e)
	{
		PRINT_COLOR(RED, e.what());
	}
	

	
	PRINT_COLOR(YELLOW, "----------TEST 04: ASSINGMENT CONSTRUCTOR----------");
	try
	{
		Array<std::string> copyArray;
		Array<std::string> TestArray(4);
		TestArray[0] = "joELEN";
		TestArray[1] = "CRUZ";
		TestArray[2] = "DA";
		TestArray[3] = "silva";
		
		copyArray = TestArray;
		copyArray[0] = "ana";

		PRINT_COLOR(BLUE, "Check for deep copy...");
		for(unsigned int i = 0; i < copyArray.size(); i++)
			PRINT_COLOR(BLUE, "copyArray[" << i << "] = " << copyArray[i])
		PRINT_COLOR(GREEN, "----------------------------------------\n");
		for(unsigned int i = 0; i < TestArray.size(); i++)
			PRINT_COLOR(BLUE, "TestArray[" << i << "] = " << TestArray[i])
	}
	catch (Array<std::string>::OutOfBoundsException& e)
	{
		PRINT_COLOR(RED, e.what());
	}


	PRINT_COLOR(YELLOW, "----------TEST 05: COPY CONSTRUCTOR----------");
	try
	{
		Array<int> TestArray(4);
		TestArray[0] = 10;
		TestArray[1] = -99;
		TestArray[2] = 200;
		TestArray[3] = 0;
		
		Array<int>copyArray(TestArray);
		copyArray[0] = 2024;

		PRINT_COLOR(BLUE, "\nCheck for deep copy...\n");
		for(unsigned int i = 0; i < copyArray.size(); i++)
			PRINT_COLOR(BLUE, "copyArray[" << i << "] = " << copyArray[i]);
		PRINT_COLOR(YELLOW, "----------------------------------------\n");
		for(unsigned int i = 0; i < TestArray.size(); i++)
			PRINT_COLOR(BLUE, "TestArray[" << i << "] = " << TestArray[i] << "\n");
	}
	catch (Array<int>::OutOfBoundsException& e)
	{
		PRINT_COLOR(RED, e.what());
	}


	PRINT_COLOR(YELLOW, "----------TEST 06: TESTING FLOAT----------");
	try
	{
		Array<float> TestArray(4);
		TestArray[0] = 1.0;
		TestArray[1] = -9.9;
		TestArray[2] = 20.3333333;
		TestArray[3] = 0;
		
		for(unsigned int i = 0; i < TestArray.size(); i++)
			PRINT_COLOR(BLUE, "TestArray[" << i << "] = " << TestArray[i]);
	}
	catch (Array<float>::OutOfBoundsException& e)
	{
		PRINT_COLOR(RED, e.what());
	}
}
