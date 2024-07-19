/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:24:23 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/07/17 22:16:39 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

// =============================================================================
// Exceptions
// =============================================================================

const char *BitcoinExchange::InvalidHeadExpetion::what() const throw()
{
    PRINT_COLOR(RED, "Invalid head format, should be 'Date | Value'");
    return ("");
}

const char* BitcoinExchange::BadInputException::what() const throw()
{
    PRINT_COLOR(RED, "Error: bad input");
	return "";
}

const char* BitcoinExchange::InvalidNumberNegative::what() const throw()
{
    PRINT_COLOR(RED, "Error: not a positive number.");
	return "";
}

const char* BitcoinExchange::InvalidNumberPositive::what() const throw()
{
    PRINT_COLOR(RED, "Error: too large a number.");
	return "";
}

// =============================================================================
// Constructors and Destructor
// =============================================================================

BitcoinExchange::BitcoinExchange(void)
{
	PRINT_COLOR(BLUE, "🪙 Default constructor called.");
    this->CreatMap();
    PRINT_COLOR(BLUE, "\n");
}


BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	if (this != &src)
		*this = src;
    PRINT_COLOR(BLUE, "🪙 Copy constructor called.");
    PRINT_COLOR(BLUE, "\n");
}


BitcoinExchange::~BitcoinExchange(void)
{
	PRINT_COLOR(BLUE, "🪙❌ Destructor called.");
    PRINT_COLOR(BLUE, "\n");
}

// =============================================================================
// Operator Overload
// =============================================================================

BitcoinExchange & BitcoinExchange::operator = (BitcoinExchange const &rhs)
{
	PRINT_COLOR(BLUE, "🪙 Assignment operator called.");
    PRINT_COLOR(BLUE, "\n");
    this->_map = rhs._map;
	return (*this);
}

// =============================================================================
// Functions
// =============================================================================

std::string cleanString(const std::string& str) {
    std::string result;
    for (unsigned long i = 0 ;i <= str.size(); i++)
    {
        if (std::isdigit(str[i]) || str[i] == '.' || str[i] == '-')
            result += str[i];
    }
    return result;
}

void	BitcoinExchange::CreatMap(void)
{
	std::ifstream	data;
	std::string		line;

	data.open("data.csv", std::ifstream::in);
	if(data.is_open())
	{
		while(getline(data, line))
		{
			size_t	sep = line.find(',');
			_map[line.substr(0, sep)] = std::strtod(cleanString(line.substr(sep + 1, line.size() - sep)).c_str(), NULL);
		}
	}
	data.close();
}

bool	BitcoinExchange::isValidDate(std::string date) const
{
	if (date.size() != 10)
		return (false);
	if (date[5] != '0' && date[5] != '1')
		return (false);
	if (date[8] > '3' || date[8] < '0')
		return (false);
	for (size_t i = 0; i < date.size(); i++)
	{
		if (!std::isdigit(date[i]) && date[i] != '-')
			return (false);
	}
	return (true);
}

std::string	BitcoinExchange::getData(std::string line) const//!melhorar
{
	size_t		sep;
	std::string	key;
   
	sep = line.find(" | ");
	if (sep == std::string::npos)
		throw BadInputException();
	key = line.substr(0, sep);
    
	if (isValidDate(key))
		return (key);
	throw BadInputException();
    return (key);
}

double	BitcoinExchange::getValue(std::string line) const //!melhorar
{
	size_t		sep;
	double		value;

	sep = line.find(" | ");
	line = line.substr(sep + 3, line.size());
	value = std::strtod(line.c_str(), NULL);
	if (value < 0)
		throw InvalidNumberNegative();
	if(value > 1000)
		throw InvalidNumberPositive();
	return (value);
}

double	BitcoinExchange::getBottomDate(const std::string& targetDate) const //!melhorar
{
	std::map<std::string, double>::const_iterator it = _map.lower_bound(targetDate);
	const std::string& returnedDate = it->first;

	if (it == _map.begin() || returnedDate == targetDate)
		return it->second;
	--it;
	return it->second;
}

bool BitcoinExchange::checkHead(std::string filename) const
{
    std::ifstream file(filename.c_str()); // Abre o arquivo
    std::string firstLine;
    
    try{
        if(!getline(file, firstLine)) // Lê a primeira linha
        {
            std::cerr << "Failed to read the first line from file: " << filename << std::endl;
            return false;
        }
        if(firstLine != "date | value"){
            throw InvalidHeadExpetion();
            return false;
        }
    }
    catch(const std::exception& e){
        std::cerr << e.what();
         exit(EXIT_FAILURE);
    }
    return true;
}

void BitcoinExchange::superCompare(std::string filename) const //!melhorar
{
    std::ifstream	file;
	std::string		line;

	file.open(filename.data(), std::ifstream::in);
    
	if(file.is_open())
	{
        
        getline(file, line);// Ignora a primeira linha (cabeçalho)
        
		while(getline(file, line))
		{
            try{
				std::string	key = getData(line);
				double		value = getValue(line);
				
				std::cout << key << " => " << value << " = " << value * getBottomDate(key) << std::endl;
			}
            catch(const std::exception& e){
                std::cerr << e.what();
            }
            
        }
    }
}

void BitcoinExchange::printData() 
{   
    
    std::map<std::string, double>::const_iterator it = _map.begin();
    
    for (int i = 0; i < 200 && it != _map.end(); ++i, ++it) 
    {
       if(i == 0)
       {
           PRINT_COLOR(GREEN, "#-#-#-#-#-#-START Printing data...-#-#-#-#-#-\n");
           PRINT_COLOR_N(YELLOW, "Date ");
           PRINT_COLOR_N(PINK, "Value\n");
       }
       
       PRINT_COLOR_N(YELLOW, it->first << " "); 
       PRINT_COLOR_N(PINK, it->second << std::endl);
    }
    
    PRINT_COLOR(GREEN, "\n#-#-#-#-#-#-#-#-#-#-#-#-\n");
}