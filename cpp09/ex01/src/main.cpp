/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:53:36 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/07/16 00:30:03 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"


int main(int argc, char* argv[]) 
{
	if (argc != 2) 
	{
		PRINT_COLOR(RED, "Usage: $./RPN \"expression\"");
		return 1;
	}

	RPN cal;
   	cal.calculate(argv[1]);

	return 0;
}