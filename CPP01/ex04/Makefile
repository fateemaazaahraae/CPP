# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiima <tiima@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 08:25:38 by tiima             #+#    #+#              #
#    Updated: 2024/11/06 14:50:27 by tiima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re