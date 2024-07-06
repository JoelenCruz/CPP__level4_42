/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:59:06 by joe               #+#    #+#             */
/*   Updated: 2024/06/29 15:03:41 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

int	main(void)
{
	PRINT_COLOR(YELLOW,"#-#-#-#-#-#-# EXEMPLE 1 #-#-#-#-#-#-#")

	Data *ptr = new Data;
	ptr->a_int = -100;
	ptr->s_sting = "BANANAS";

	uintptr_t serialized;
	serialized = Serializer::serialize(ptr);
	
	Data* deserialized = Serializer::deserialize(serialized);
	
	if (deserialized->a_int == 2 && deserialized->s_sting == ptr->s_sting)
		PRINT_COLOR(BLUE,"Success")
	else
		PRINT_COLOR(RED,"Error!!")

	delete ptr;



	PRINT_COLOR(YELLOW,"#-#-#-#-#-#-# EXEMPLE 2 #-#-#-#-#-#-#")
	
	Data data;
    data.a_int = -42;

	// Serialização
    uintptr_t raw = Serializer::serialize(&data);
    PRINT_COLOR(BLUE,"Serialized")
	PRINT_COLOR(GREEN,raw)

    // Desserialização
    Data *deserializedData = Serializer::deserialize(raw);
	PRINT_COLOR(BLUE,"Deserialized value:")
	PRINT_COLOR(GREEN,deserializedData->a_int)
	return (0);
}
