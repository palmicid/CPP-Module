# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 12:37:19 by pruangde          #+#    #+#              #
#    Updated: 2023/07/28 02:32:25 by pruangde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= moreFixed

CC 			= c++
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -std=c++98

SRC			= main.cpp Fixed.cpp
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
