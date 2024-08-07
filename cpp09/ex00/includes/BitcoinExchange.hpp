/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:31:51 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/07/17 22:04:11 by jcruz-da         ###   ########.fr       */
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

		/*Auxiliar Functions*/
		void CreatMap(void);
		double getBottomDate(const std::string& targetDate) const;
		bool isValidDate(std::string date) const;
		bool isValidValue(double value) const;
		std::string getData(std::string line) const;
		double getValue(std::string line) const;
		
	
	
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& a);
		BitcoinExchange& operator=(const BitcoinExchange& a);

		/*Main Functions*/
		void printData();
		void superCompare(std::string search) const;
		bool checkHead(std::string filename) const;

		
		

	
	


		class	BadInputException : public std::exception
		{
			public:
			const char* what() const throw();
		};

		class	InvalidHeadExpetion : public std::exception
		{
			public:
			const char* what() const throw();
		};

		class	InvalidNumberNegative : public std::exception
		{
			public:
			const char* what() const throw();
		};

		class	InvalidNumberPositive : public std::exception
		{
			public:
			const char* what() const throw();
		};

		
};