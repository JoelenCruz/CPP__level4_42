/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:17:09 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/03/29 17:26:40 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

bool	search_empty(std::string search)
{
	if (!search.length())
	{
		std::cerr << "ERROR: can't replace an empty string." << std::endl;
		return (true);
	}
	return (false);
}

void replaceAll(std::string& str, const std::string& from, const std::string& to) 
{
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) 
    {
        str = str.substr(0, start_pos) + to + str.substr(start_pos + from.length());
        start_pos += to.length();
    }
}

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) 
{
    std::ifstream inputFile(filename.c_str());
    if (!inputFile) {
        std::cerr << "Error: Unable to open input file " << filename << std::endl;
        return;
    }

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile) 
    {
        std::cerr << "Error: Unable to create output file " << filename << ".replace" << std::endl;
        return;
    }

    std::string line;
    
    while (std::getline(inputFile, line)) 
    {
        replaceAll(line, s1, s2);
        outputFile << line << std::endl;
    }

    std::cout << "File " << filename << " successfully processed. Replaced " << s1 << " with " << s2 << std::endl;
}