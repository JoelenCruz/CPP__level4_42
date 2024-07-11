/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:59:06 by joe               #+#    #+#             */
/*   Updated: 2024/07/11 20:41:12 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

# include <iostream>
# include <string>

int	main(void)
{
	{
		PRINT_COLOR(YELLOW,"\n#-#-#-#-#-#- CHAR -#-#-#-#-#-#-\n");
		char arr[] = {'J', 'O', 'E'};
		
		iter<char>(arr, sizeof(arr)/sizeof(char), print);
	}
	
	{	
		PRINT_COLOR(YELLOW,"\n#-#-#-#-#-#- STRING -#-#-#-#-#-#-\n");
		std::string arr[] = {"42_Porto", "42_Rio", "42_Lisboa"};
		
		iter<std::string>(arr, sizeof(arr)/sizeof(std::string), print);
	}
	
	{
		PRINT_COLOR(YELLOW,"\n#-#-#-#-#-#- INT -#-#-#-#-#-#-\n");
		int arr[] = {-1, -42, 101010};
	
		iter<int>(arr, sizeof(arr)/sizeof(int), print);
	}

	{
		PRINT_COLOR(YELLOW,"\n#-#-#-#-#-#- FLOAT #-#-#-#-#-#-\n");
		float arr[] = {1.23, 2.45, 42.333333};
	
		iter<float>(arr, sizeof(arr)/sizeof(float), print);
	}

	{
		PRINT_COLOR(YELLOW,"\n#-#-#-#-#-#- BOOL TEST #-#-#-#-#-#-\n");
		bool arr[] = {true, false, true};
	
		iter<bool>(arr, sizeof(arr)/sizeof(bool), print);
	}
	return (0);
}