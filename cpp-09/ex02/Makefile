# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 12:37:19 by pruangde          #+#    #+#              #
#    Updated: 2024/01/15 22:01:20 by pruangde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= PmergeMe

CC 			= c++
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address
CPPFLAGS	= -std=c++98

SRC			= main.cpp #PmergeMe.cpp
OBJ			= $(SRC:%.cpp=%.o)

RM			= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# No using namespace
# No STL
# No <algorithm> header
# No containers (vector/list/map/and so forth) allow in 08 and 09

# from 02 to 09
# classes must be designed in the Orthodox Canonical Form
# except when explicitely stated otherwise

# must avoid the problem of double inclusion 
# by adding include guards.

# in 09 
# ex00 - map
# ex01 - stack
# ex02 - 
