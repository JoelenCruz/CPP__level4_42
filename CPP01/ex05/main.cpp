/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:24:45 by joe               #+#    #+#             */
/*   Updated: 2024/03/01 13:34:01 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

//TODO: verificar se o erro de não  ter break no switch é aceitavel

bool checkArg(int argc)
{
    if (argc != 2)
    {
        ERROR("Usage: ./harlFilter [ DEBUG | INFO | WARNING | ERROR ]");
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