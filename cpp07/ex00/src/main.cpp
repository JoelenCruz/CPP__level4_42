/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:59:23 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/07/11 20:28:05 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../includes/whatever.hpp"

int main( void ) 
{
	int a = 2;
	int b = 3;
	
	{
		::swap( a, b );
		PRINT_COLOR(BLUE,"a = " << a << ", b = " << b);
		PRINT_COLOR(BLUE,"min(a, b) = " << ::min( a, b ));
		PRINT_COLOR(BLUE,"max(a, b) = " << ::max( a, b ));
	}

	
	std::string c = "chaine1";
	std::string d = "chaine2";

	{
		::swap(c, d);
		PRINT_COLOR(BLUE,"c = " << c << ", d = " << d);
		PRINT_COLOR(BLUE,"min(c, d) = " << ::min( c, d ));
		PRINT_COLOR(BLUE,"max(c, d) = " << ::max( c, d ));
	}


	// float e = 12.5;
	// float f = 18.5;

	// {
	// 	::swap(c, d);
	// 	PRINT_COLOR(BLUE,"e = " << e << ", f = " << f);
	// 	PRINT_COLOR(BLUE,"min(e, f) = " << ::min( e, f ));
	// 	PRINT_COLOR(BLUE,"max(e, f) = " << ::max( e, f ));
	// }
	
	
	return 0;
}

