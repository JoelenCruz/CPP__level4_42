/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:24:23 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/07/14 15:36:47 by jcruz-da         ###   ########.fr       */
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


const char *BitcoinExchange::InvalidDateExpetion::what() const throw()
{
    PRINT_COLOR(RED, "Invalid date format, should be 'YYYY-MM-DD'");
    return ("");
}

const char *BitcoinExchange::YearInvalidExpetion::what() const throw()
{
    PRINT_COLOR(RED, "Yea2012-01-11 | -1r is not a valid number");
    return ("");
}

const char *BitcoinExchange::MonthInvalidExpetion::what() const throw()
{
    PRINT_COLOR(RED, "Month is not a valid number");
    return ("");
}

const char *BitcoinExchange::DayInvalidExpetion::what() const throw()
{
    PRINT_COLOR(RED, "Day is not a valid number");
    return ("");
}

const char *BitcoinExchange::MonthDayInvalidExpetion::what() const throw()
{
    PRINT_COLOR(RED, "Month or day is out of range");
    return ("");
}

const char *BitcoinExchange::OutFebruaryInvalidExpetion::what() const throw()
{
    PRINT_COLOR(RED, "Out February range");
    return ("");
}


const char* BitcoinExchange::BadInputException::what() const throw()
{
    PRINT_COLOR(RED, "Error: bad input");
	return "";
}

const char* BitcoinExchange::InvalidNumberExpetion::what() const throw()
{
    PRINT_COLOR(RED, "Error: Value is out of range");
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

bool  BitcoinExchange::isValidValue(double value) const //usar?
{
    try 
    {
        if (value < 0 || value > 1000000)
            throw InvalidNumberExpetion();
    }
    catch (const std::exception& e) 
    {
        std::cerr <<  e.what();
        return (false);
    }
    
    return (true);
}

bool BitcoinExchange::isValidDate(const std::string date) const
{
    std::string year, month, day;
    size_t firstHyphen = date.find('-');
    size_t secondHyphen = date.find('-', firstHyphen + 1);

    year = date.substr(0, firstHyphen);
    month = date.substr(firstHyphen + 1, secondHyphen - firstHyphen - 1);
    day = date.substr(secondHyphen + 1);

    try 
    {
        if(year.size() != 4 || month.size() != 2 || day.size() != 2)
        {   
            throw BitcoinExchange::InvalidDateExpetion();
            return false;
        }
            

        // Check if year, month, and day are all digits
        for(std::string::iterator it = year.begin(); it != year.end(); ++it)
            if(!isdigit(*it))
            {
                throw BitcoinExchange::YearInvalidExpetion();
                return false;
            }
                
                
        for(std::string::iterator it = month.begin(); it != month.end(); ++it)
            if(!isdigit(*it))
            {
                throw BitcoinExchange::MonthInvalidExpetion();
                 return false;
            }
                
                
        for(std::string::iterator it = day.begin(); it != day.end(); ++it)
            if(!isdigit(*it))
            {
                throw BitcoinExchange::DayInvalidExpetion();
                return false;
            }
                 

        // Convert month and day to int and check if they are valid
        int month_int = atoi(month.c_str());
        int day_int = atoi(day.c_str());


        if(month_int < 1 || month_int > 12 || day_int < 1 || day_int > 31)
        {
            throw BitcoinExchange::MonthDayInvalidExpetion();
            return false;
        }
        
        // Check february 29, 30 and 31 
        if(month_int == 2 && day_int >= 29)
        {
            throw BitcoinExchange::OutFebruaryInvalidExpetion();
            return false;
        }
            
    }
    catch (const std::exception& e) 
    {
        std::cerr <<  e.what();
    }
    return true;
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
}



double	BitcoinExchange::getValue(std::string line) const //!melhorar
{
	size_t		sep;
	double		value;

	sep = line.find(" | ");
	line = line.substr(sep + 3, line.size());
	value = std::strtod(line.c_str(), NULL);
	if (!isValidValue(value))
		return (0);
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
        if(firstLine != "Date | Value"){
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


