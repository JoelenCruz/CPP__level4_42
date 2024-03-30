# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 12:50:53 by joe               #+#    #+#              #
#    Updated: 2024/03/29 15:45:13 by jcruz-da         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *==============================================================================
# *VARIABLES
# *==============================================================================

NAME		:=	harlFilter
CXX			:=	c++
CXXFLAGS	:=	-Wall -Werror -Wextra -std=c++98 -Wno-error=implicit-fallthrough
HEADERS		:=	./Harl.hpp
SRCS		:=	./main.cpp ./Harl.cpp
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

%.o:	%.cpp $(HEADERS)
			@echo $(ITALIC_GRAY) Compiling $<$(EOC)
			$(CXX) $(CXXFLAGS) -c $< -o $@

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