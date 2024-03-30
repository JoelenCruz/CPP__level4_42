/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:18:40 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/03/29 17:20:10 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __REPLACE_HPP
#define __REPLACE_HPP

# include <iostream>	// std::cout, std::string
# include <fstream>		// std::ifstream, std::ofstream

bool	search_empty(std::string search);
void replaceAll(std::string& str, const std::string& from, const std::string& to);
void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2);

#endif