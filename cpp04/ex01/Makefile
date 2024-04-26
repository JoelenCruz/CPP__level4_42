# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 15:47:57 by jcruz-da          #+#    #+#              #
#    Updated: 2024/04/21 17:22:25 by jcruz-da         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# *==============================================================================
# *VARIABLES
# *==============================================================================

NAME		:=	Brain
CXX			:=	c++
CXXFLAGS	:=	-Wall -Werror -Wextra -std=c++98
HEADERS		:=	./includes
SRCS		:=	./src/Brain.cpp ./src/Animal.cpp ./src/Dog.cpp ./src/Cat.cpp ./src/WrongAnimal.cpp ./src/WrongCat.cpp ./src/main.cpp 
OBJS		:=	$(SRCS:.cpp=.o)

# *==============================================================================
# *COLORS
# *==============================================================================

EOC				:=	"\e[0m"
ITALIC_GRAY		:=	"\e[3;37m"
ITALIC_MAGENTA	:=	"\e[1;3;35m"
ITALIC_GREEN 	:= 	"\e[1;3;32m"

# *==============================================================================
# *DEBUG
# *==============================================================================

ifdef DEBUG
	CFLAGS		+= -g -fsanitize=address
endif

# *==============================================================================
# *ROLES
# *==============================================================================

all:		$(NAME)

%.o:	%.cpp 
			@echo $(ITALIC_GRAY) Compiling $<$(EOC)
			$(CXX) $(CXXFLAGS) -I $(HEADERS) -c  $< -o $@

$(NAME):	$(OBJS)
			@echo $(ITALIC_GREEN)$(NAME) created! $(EOC)
			$(CXX) $(OBJS) $(CXXFLAGS) -o $@

debug:
	$(CXX) -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address  -o $(NAME) $(SRCS)

clean:
			@rm -rf $(OBJS)
			@echo $(ITALIC_MAGENTA)"Objects deleted"$(EOC)

fclean:		clean
			@rm -f $(NAME)
			@echo $(ITALIC_MAGENTA)$(NAME)" deleted"$(EOC)

re:			fclean all

.PHONY:		all clean fclean re