/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:21:23 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/07/08 19:45:36 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>	// std::cout, std::cerr
#include <cmath>	// std::isnan, std::isinf
#include <cstdlib>	// std::atoi
#include <limits>	// std::numeric_limits
#include <iomanip>	// std::setprecision


#define RESET_COLOR "\033[0m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define PINK "\033[35m"

#define PRINT_COLOR(color, message) std::cout << color << message << RESET_COLOR << std::endl;

typedef std::numeric_limits<char> LimitsChar;
typedef std::numeric_limits<int> LimitsInt;
typedef std::numeric_limits<float> LimitsFloat;


enum e_type
{
	CHAR = 0,
	INT = 1,
	FLOAT = 2,
	DOUBLE = 3,
	INVALID = 4,
};

// =============================================================================
// Class
// =============================================================================

class ScalarConverter
{
	private:
		/* Orthodox Canonical Form Methods */
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter &operator = (ScalarConverter const &rhs);
		~ScalarConverter(void);

		/* Get type */
		static int	get_type(const std::string str);
		static bool	is_char(const std::string &str);
		static bool	is_int(const std::string &str);
		static bool	is_float(const std::string &str);
		static bool	is_double(const std::string &str);
		static bool	is_all_digits(const std::string &str, int type);
		static int	is_infinity(const std::string &str);

		/* Char conversion */
		static void	convert_to_char(const std::string &str);
		
		/* Int conversion */
		static void	convert_to_int(const std::string &str);
		static bool	is_overflow(const std::string &str);
		
		/* Float conversion */
		static void	convert_to_float(const std::string &str);
		
		/* Double conversion */
		static void	convert_to_double(const std::string &str);

		/* Print functions */
		static void	print_char(char c);
		static void	print_int(int d);
		static void	print_float(float f);
		static void	print_double(double d);
		static void	print_impossible(const std::string type);
		
		/* Impossible conversion */
		static void	impossible_conversion(void);
		

	public:
		static void	convert(const std::string str);
	
	class UnknownTypeException : public std::exception
	{
		public:
		const char * what() const throw();
	};

	/*
	When should static_cast, dynamic_cast, const_cast, and reinterpret_cast 
	be used?
	<static_cast>
	This is used for the normal/ordinary type conversion. This is also the 
	cast responsible for implicit type conversion and can also be called 
	explicitly. You should use it in cases like converting float to int, char 
	to int, etc.

	https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used
	*/
};