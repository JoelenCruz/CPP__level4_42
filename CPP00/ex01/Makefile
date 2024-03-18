# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 15:37:11 by joe               #+#    #+#              #
#    Updated: 2024/03/18 15:45:39 by jcruz-da         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==============================================================================
# VARIABLES
# ==============================================================================

NAME		:=	PhoneBook
CC			:=	c++
CFLAGS		:=	-Wall -Werror -Wextra -std=c++98
HEADERS		:=	./includes/Contact.hpp	./includes/PhoneBook.hpp	
SRCS		:=	./sources/Contact.cpp	./sources/PhoneBook.cpp		./sources/main.cpp
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

%.o:	source/%.cpp
			@$(ECHO) Compiling $< $(EOC)
			@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@


$(NAME):	$(OBJS)
			@echo $(ITALIC_GREEN)$(NAME) created! $(EOC)
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
