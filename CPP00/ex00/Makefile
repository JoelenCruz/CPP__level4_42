# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joe <joe@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 13:52:02 by joe               #+#    #+#              #
#    Updated: 2024/02/08 13:19:10 by joe              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *==============================================================================
# *VARIABLES
# *==============================================================================

NAME		:=	megaphone
CC			:=	c++
CFLAGS		:=	-Wall -Werror -Wextra -std=c++98
HEADERS		:=	includes
SRCS		:=	megaphone.cpp

OBJS		:=	$(SRCS:.cpp=.o)

# *==============================================================================
# *COLORS
# *==============================================================================

EOC				:=	"\e[0m"
ITALIC_GRAY		:=	"\e[3;37m"
ITALIC_MAGENTA	:=	"\e[1;3;35m"

# *==============================================================================
# *BUILD PERCENTAGE
# *==============================================================================

ifndef ECHO
	T := $(shell $(MAKE) $(MAKECMDGOALS) -n ECHO="counter" | grep -c "counter")
endif

ifeq ($(firstword $(MAKECMDGOALS)), $(shell echo re))
	T := $(shell expr $(words $(OBJS)) + 1)
endif

PRINT	:=	$(shell which echo) -e
N := x
C = $(words $(N))$(eval N := x $(N))
P = "`expr $(C) '*' 100 / $(T)`"
ECHO = $(PRINT) $(ITALIC_GRAY)"[$(P)%]\t"

# *==============================================================================
# *RECIPES
# *==============================================================================

all:		$(NAME)

%.o:	%.cpp
			@$(ECHO) Compiling $< $(EOC)
			@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

$(NAME):	$(OBJS)
			@$(ECHO) $(NAME) created! $(EOC)
			@$(CC) $(OBJS) $(CFLAGS) -o $@

clean:
			@rm -rf $(OBJS)
			@$(PRINT) $(ITALIC_MAGENTA)"Objects deleted"$(EOC)

fclean:		clean
			@rm -f $(NAME)
			@$(PRINT) $(ITALIC_MAGENTA)$(NAME)" deleted"$(EOC)

re:			fclean all

test:		all
			./$(NAME)

.PHONY:		all clean fclean re test