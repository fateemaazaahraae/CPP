# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiima <tiima@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 16:13:43 by fbazaz            #+#    #+#              #
#    Updated: 2024/12/05 09:45:58 by tiima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Contact.cpp Contact_utils.cpp main.cpp PhoneBook.cpp

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re