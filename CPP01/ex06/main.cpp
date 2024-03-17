/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:10:37 by joe               #+#    #+#             */
/*   Updated: 2024/03/01 13:11:02 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

bool checkArg(int argc)
{
    if (argc != 2)
    {
        ERROR("Usage: ./harl [DEBUG | INFO | WARNING | ERROR]");
        return (false);
    }
    return (true);
}

int main(int argc, char **argv)
{
     Harl harl;
     
    if (!checkArg(argc))
        return (1);
   
    harl.complain(argv[1]);
    return (0);
}