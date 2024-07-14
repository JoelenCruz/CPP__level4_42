/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:31:51 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/07/14 01:06:19 by jcruz-da         ###   ########.fr       */
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

#define PRINT_COLOR_N(color, message) std::cout << color << message << RESET_COLOR;


#include <map> // for map
#include <iostream> // std::cout, std::cerr
#include <fstream> 
#include <sstream>
 #include <algorithm>


class BitcoinExchange
{
	private:
		std::map<std::string, double> _map;

		void CreatMap(void);
		double getBottomDate(const std::string& targetDate) const;
		bool isValidDate(std::string date) const;
		std::string getData(std::string line) const;
		double getValue(std::string line) const;
		
	
	
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& a);
		BitcoinExchange& operator=(const BitcoinExchange& a);


		void printData();
		void superCompare(std::string search) const;
		
		class	InvalidDateExpetion : public std::exception
		{
			public:
			const char* what() const throw();
		};

		class	YearInvalidExpetion : public std::exception
		{
			public:
			const char* what() const throw();
		};

		class	MonthInvalidExpetion : public std::exception
		{
			public:
			const char* what() const throw();
		};

		class	DayInvalidExpetion : public std::exception
		{
			public:
			const char* what() const throw();
		};

		class	MonthDayInvalidExpetion : public std::exception
		{
			public:
			const char* what() const throw();
		};

		class	OutFebruaryInvalidExpetion : public std::exception
		{
			public:
			const char* what() const throw();
		};

		class	BadInputException : public std::exception
		{
			public:
			const char* what() const throw();
		};

		class	NotAPositiveNumberException : public std::exception
		{
			public:
			const char* what() const throw();
		};
		class	TooLargeNumberException : public std::exception
		{
			public:
			const char* what() const throw();
		};

		
};