/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:56:04 by joe               #+#    #+#             */
/*   Updated: 2024/02/26 20:26:32 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

//TODO: add a check for empty string
//TODO: organaize the code into functions and classes
//TODO: o que fazer sobre as strings vazias?
//TODO: o que quando o codigo nao encontra a string pra substituir?

bool	search_empty(std::string search)
{
	if (!search.length())
	{
		std::cerr << "ERROR: can't replace an empty string." << std::endl;
		return (true);
	}
	return (false);
}

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) 
    {
        str = str.substr(0, start_pos) + to + str.substr(start_pos + from.length());
        start_pos += to.length();
    }
}

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    std::ifstream inputFile(filename.c_str());
    if (!inputFile) {
        std::cerr << "Error: Unable to open input file " << filename << std::endl;
        return;
    }

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile) {
        std::cerr << "Error: Unable to create output file " << filename << ".replace" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        replaceAll(line, s1, s2);
        outputFile << line << std::endl;
    }

    std::cout << "File " << filename << " successfully processed. Replaced " << s1 << " with " << s2 << std::endl;
}

int main(int argc, char *argv[]) 
{
    if (argc != 4) 
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (search_empty(s1) || search_empty(s2))
        return 1;
    else
        replaceInFile(filename, s1, s2);

    return 0;
}



