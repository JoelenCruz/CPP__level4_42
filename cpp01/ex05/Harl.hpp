/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:24:41 by joe               #+#    #+#             */
/*   Updated: 2024/03/01 12:20:18 by joe              ###   ########.fr       */
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