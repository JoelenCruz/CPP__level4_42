/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl_filter.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:40:48 by joe               #+#    #+#             */
/*   Updated: 2024/03/01 12:40:50 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

#define PRINT(string) std::cout << string << std::endl;
#define ERROR(string) std::cout << "Error: " << string << std::endl;

class Harl
{
    private:
        void warning(void);
        void debug(void);
        void error(void);    
        void info(void);
    
    public:
        Harl(void);
        ~Harl(void);

        void complain(std::string level);
};
#endif