# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiima <tiima@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 09:37:26 by tiima             #+#    #+#              #
#    Updated: 2024/11/19 15:30:56 by tiima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Fixed.cpp

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