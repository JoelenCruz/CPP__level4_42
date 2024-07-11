/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:59:06 by joe               #+#    #+#             */
/*   Updated: 2024/07/08 20:36:54 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

int	main(void)
{
	{
		PRINT_COLOR(YELLOW,"#-#-#-#-#-#-# EXEMPLE 1 #-#-#-#-#-#-#")

		Data *ptr = new Data;
		ptr->a_int = -100;
		ptr->s_sting = "BANANAS";

		uintptr_t raw;
		raw = Serializer::serialize(ptr);
		
		Data* deserialized = Serializer::deserialize(raw);
		
		if ((deserialized->a_int == -10) && (deserialized->s_sting == ptr->s_sting))
		{
			PRINT_COLOR(GREEN,"Success")
			PRINT_COLOR(BLUE,"Serialized: " << raw);
			PRINT_COLOR(BLUE,"Deserialized number: " << deserialized->a_int)
			PRINT_COLOR(BLUE,"Deserialized string: " << deserialized->s_sting)
		}
		else
		{
			PRINT_COLOR(RED,"Error!!")
			PRINT_COLOR(BLUE,"Serialized: " << raw);
			PRINT_COLOR(BLUE,"Deserialized number: " << deserialized->a_int)
			PRINT_COLOR(BLUE,"Deserialized string: " << deserialized->s_sting)
		}
		delete ptr;
	}

	
	{	
		PRINT_COLOR(YELLOW,"\n#-#-#-#-#-#-# EXEMPLE 2 #-#-#-#-#-#-#")
		
		Data data;
		data.a_int = -42;

		// Serialização
		uintptr_t raw = Serializer::serialize(&data);
		PRINT_COLOR(BLUE,"Serialized: " << raw);

		// Desserialização
		Data *deserializedData = Serializer::deserialize(raw);
		PRINT_COLOR(BLUE,"Deserialized value:" << deserializedData->a_int);
	}
	return (0);
}
