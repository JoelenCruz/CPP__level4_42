# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joe <joe@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 19:17:08 by joe               #+#    #+#              #
#    Updated: 2024/03/01 11:54:24 by joe              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *==============================================================================
# *VARIABLES
# *==============================================================================

NAME		:=	weapon
CC			:=	c++
CFLAGS		:=	-Wall -Werror -Wextra -std=c++98
HEADERS		:=	./Weapon.hpp ./HumanA.hpp ./HumanB.hpp
SRCS		:=	./main.cpp  Weapon.cpp  HumanA.cpp HumanB.cpp
OBJS		:=	$(SRCS:.cpp=.o)

# *==============================================================================
# *COLORS
# *==============================================================================

EOC				:=	"\e[0m"
ITALIC_GRAY		:=	"\e[3;37m"
ITALIC_MAGENTA	:=	"\e[1;3;35m"
ITALIC_GREEN 	:= 	"\e[3;32m"

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

%.o:	%.cpp $(HEADERS)
			@echo $(ITALIC_GREEN) Compiling $<$(EOC)
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			@echo $(NAME) created! $(EOC)
			@$(CC) $(OBJS) $(CFLAGS) -o $@

debug:
	$(CC) -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address  -o $(NAME) $(SRCS)

clean:
			@rm -rf $(OBJS)
			@echo $(ITALIC_MAGENTA)"Objects deleted"$(EOC)

fclean:		clean
			@rm -f $(NAME)
			@echo $(ITALIC_MAGENTA)$(NAME)" deleted"$(EOC)

re:			fclean all

.PHONY:		all clean fclean re