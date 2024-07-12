/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:59:23 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/07/12 19:23:01 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "../includes/easyfind.hpp"


template<typename T>
void testContainer(T& container, int value)
{
    try {
    	easyfind(container, value);
       	PRINT_COLOR(GREEN, value << " was found in the container.")
    } catch (const std::runtime_error& e){
       	PRINT_COLOR(RED,e.what());
    }
}

int main()
{
    std::vector<int> numbers_vector;
    std::list<int> numbers_list;
    std::deque<int> numbers_deque;

    for (int i = 1; i <= 5; ++i) {
        numbers_vector.push_back(i);
        numbers_list.push_back(i);
        numbers_deque.push_back(i);
    }

    testContainer(numbers_vector, 3);
    testContainer(numbers_list, 3);
    testContainer(numbers_deque, 3);

    testContainer(numbers_vector, 6);
    testContainer(numbers_list, 6);
    testContainer(numbers_deque, 6);

    return 0;
}
