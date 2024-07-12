/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:59:06 by joe               #+#    #+#             */
/*   Updated: 2024/07/12 22:11:50 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

void teste_subjet()
{
	try
	{
		Span sp = Span(6);
	
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(110000000);
		PRINT_COLOR(GREEN, "shortestSpan --> " << sp.shortestSpan());
		PRINT_COLOR(GREEN,"longestSpan --> " << sp.longestSpan());
		PRINT_COLOR(YELLOW, "-#-#-#-#-#-#-#-#-#-#-#-#-#-"); 
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
}	

void test_pop(void)
{
    Span sp2(100);
    std::vector<int> inter(10);  

    std::srand(std::time(0));

    for(std::vector<int>::iterator it = inter.begin(); it != inter.end(); ++it) 
    {
        *it = std::rand() % 1000;  // Generate random number between 0 and 999
		PRINT_COLOR(BLUE, *it);
    }

	try
	{
		sp2.addNumber(inter.begin(), inter.end());
		PRINT_COLOR(GREEN, "shortestSpan --> " << sp2.shortestSpan());
		PRINT_COLOR(GREEN,"longestSpan --> " << sp2.longestSpan());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}


int main()
{
	teste_subjet();
	
	test_pop();
	return 0;
}