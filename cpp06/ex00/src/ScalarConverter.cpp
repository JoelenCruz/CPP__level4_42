/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:23:01 by harndt            #+#    #+#             */
/*   Updated: 2024/07/08 20:03:02 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// =============================================================================
// Exception
// =============================================================================

const char * ScalarConverter::UnknownTypeException::what() const throw()
{
	PRINT_COLOR(RED, "Type not supported!!");
	 return"";
}


// =============================================================================
// Constructors and Destructor
// =============================================================================

ScalarConverter::ScalarConverter(void)
{
	PRINT_COLOR(BLUE, "Default constructor called.");
}


ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	PRINT_COLOR(BLUE, "🔄 Copy constructor called.");
	(void)src;
}


ScalarConverter::~ScalarConverter(void)
{
	PRINT_COLOR(BLUE, "🔄 Destructor called.");
}

// =============================================================================
// Operator Overload
// =============================================================================

ScalarConverter & ScalarConverter::operator = (ScalarConverter const &rhs)
{
	PRINT_COLOR(BLUE, "🔄 Assignment operator called.");
	(void)rhs;
	return (*this);
}

// =============================================================================
// functions
// =============================================================================


int		ScalarConverter::is_infinity(const std::string &str)
{
	if (!str.compare("-inff") || !str.compare("+inff") || !str.compare("nanf"))
		return (FLOAT);
	if (!str.compare("-inf") || !str.compare("+inf") || !str.compare("nan"))
		return (DOUBLE);
	return (INVALID);
}


bool	ScalarConverter::is_all_digits(const std::string &str, int type)
{
	unsigned int	i = 0;
	unsigned int	points = 0;
	unsigned int	f = 0;

	if (str[0] == '+' || str[0] == '-')
		i++;
	if (type == INT)
	{
		while (i < str.length())
		{
			if (!isdigit(str[i++]))
				return (false);
		}
	}
	else if (type == FLOAT)
	{
		while (i < str.length())
		{
			if (str[i] == '.')
				points++;
			if (str[i] == 'f')
				f++;
			if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
				return (false);
			if (points == 2 || f == 2)
				return (false);
			i++;
		}
	}
	else
		return (false);
	return (true);
}


bool	ScalarConverter::is_char(const std::string &str)
{
	if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		return (true);
	return (false);
}


bool	ScalarConverter::is_int(const std::string &str)
{
	if (is_all_digits(str, 1) && str.length() < 16)
		return (true);
	return (false);
}

bool	ScalarConverter::is_float(const std::string &str)
{
	size_t dlength = str.length() - 1;

	if (str[dlength] != 'f')
		return (false);
	if (is_infinity(str) == FLOAT)
		return (true);
	if (is_all_digits(str, FLOAT) && str.find('.') <= 16)
		return (true);
	return (false);
}


bool	ScalarConverter::is_double(const std::string &str)
{
	if (is_infinity(str) == DOUBLE)
		return (true);
	if (is_all_digits(str, 2) && str.find('.') <= 16)
		return (true);
	return (false);
}


int	ScalarConverter::get_type(const std::string str)
{
	if (str.empty())
		return (INVALID);
	if (is_char(str))
		return (CHAR);
	if (is_int(str))
		return (INT);
	if (is_float(str))
		return (FLOAT);
	if (is_double(str))
		return (DOUBLE);
	return (INVALID);
}

// =============================================================================
// Char conversion
// =============================================================================


void	ScalarConverter::convert_to_char(const std::string &str)
{
	print_char(str[0]);
	print_int(static_cast<int>(str[0]));
	print_float(static_cast<float>(str[0]));
	print_double(static_cast<double>(str[0]));
}

// =============================================================================
// Int conversion
// =============================================================================

bool	ScalarConverter::is_overflow(const std::string &str)
{
	long int	of = std::atol(str.c_str());
	
	if (of >= LimitsInt::min() && of <= LimitsInt::max())
		return (true);
	print_impossible("char");
	print_impossible("int");
	print_float(static_cast<float>(of));
	print_double(static_cast<double>(of));
	return (false);
}


void	ScalarConverter::convert_to_int(const std::string &str)
{
	if (!is_overflow(str))
		return ;
	int	nb = std::atoi(str.c_str());
	
	if (nb < LimitsChar::min() || nb > LimitsChar::max())
		print_impossible("char");
	else
		print_char(static_cast<char>(nb));
	print_int(nb);
	print_float(static_cast<float>(nb));
	print_double(static_cast<double>(nb));
}

// =============================================================================
// Float conversion
// =============================================================================


void	ScalarConverter::convert_to_float(const std::string &str)
{
	float	nb = std::strtof(str.c_str(), NULL);

	if (nb < LimitsChar::min() || nb > LimitsChar::max() || std::isnan(nb) || std::isinf(nb))
		print_impossible("char");
	else
		print_char(static_cast<char>(nb));
	
	if (nb < LimitsInt::min() || nb > LimitsInt::max() || std::isnan(nb) || std::isinf(nb))
		print_impossible("int");
	else
		print_int(static_cast<int>(nb));
	print_float(nb);
	print_double(static_cast<double>(nb));
}

// =============================================================================
// Double conversion
// =============================================================================


void	ScalarConverter::convert_to_double(const std::string &str)
{
	double	nb = std::strtod(str.c_str(), NULL);

	if (nb < LimitsChar::min() || nb > LimitsChar::max() || std::isnan(nb) || std::isinf(nb))
		print_impossible("char");
	else
		print_char(static_cast<char>(nb));
	if (nb < LimitsInt::min() || nb > LimitsInt::max() || std::isnan(nb) || std::isinf(nb))
		print_impossible("int");
	else
		print_int(static_cast<int>(nb));
	if (nb < LimitsFloat::min() || nb > LimitsFloat::max())
		print_impossible("float");
	else
		print_float(static_cast<float>(nb));
	print_double(nb);
}

// =============================================================================
// Print functions
// =============================================================================


void	ScalarConverter::print_char(char c)
{
	if (std::isprint(c))
	{
		PRINT_COLOR(BLUE, "char: '" << c << "'");
	}
	else
	{
		PRINT_COLOR(RED, "char: Non displayable");
	}
}


void	ScalarConverter::print_int(int d)
{
	PRINT_COLOR(BLUE, "int: " << d);
}


void	ScalarConverter::print_float(float f)
{
	PRINT_COLOR(BLUE, "float: " << std::fixed << std::setprecision(1) << f << "f");
}


void	ScalarConverter::print_double(double d)
{
	PRINT_COLOR(BLUE,"double: " << std::fixed << std::setprecision(1) << d); 
}


void	ScalarConverter::print_impossible(const std::string type)
{
	PRINT_COLOR(RED,type << " impossible!"); 
}


void	ScalarConverter::impossible_conversion(void)
{	
	print_impossible("char");
	print_impossible("int");
	print_impossible("float");
	print_impossible("double");
}
// =============================================================================
// Convert function
// =============================================================================


void	ScalarConverter::convert(const std::string str)
{
	int	type = get_type(str);

	switch (type)
	{
		case CHAR:
			convert_to_char(str);
			break;
		case INT:
			convert_to_int(str);
			break;
		case FLOAT:
			convert_to_float(str);
			break;
		case DOUBLE:
			convert_to_double(str);
			break;
		default :
			impossible_conversion();
	}
}