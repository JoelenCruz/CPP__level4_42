// **************************************************************************** #
//                                                                               #
//                                                          :::      ::::::::    #
//     Makefile                                           :+:      :+:    :+:    #
//                                                      +:+ +:+         +:+      #
//     By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+         #
//                                                  +#+#+#+#+#+   +#+            #
//     Created: 2024/04/21 17:20:57 by jcruz-da          #+#    #+#              #
//     Updated: 2024/04/21 17:22:25 by jcruz-da         ###   ########.fr        #
//                                                                               #
// ***************************************************************************** #

#pragma once

#include <iostream>

#define PRINT(x) std::cout << x << std::endl;
#define IDEAS 100

class Brain
{
    private:
        std::string     _ideas[IDEAS];

    public:
        Brain(void);
        Brain(Brain const &src);
        Brain &operator = (Brain const &rhs);
        ~Brain(void);

        void setIdea(size_t i, std::string idea);
        std::string getIdea(size_t i) const;
};



