# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 00:37:39 by pruangde          #+#    #+#              #
#    Updated: 2023/07/19 02:53:40 by pruangde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= PhoneBook

CC 			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
CPPFLAGS	= -std=c++98

RM			= rm -rf

FILE = main.cpp Contact.cpp PhoneBook.cpp

all:
	$(CC) $(CFLAGS) $(CPPFLAGS) $(FILE) -o $(NAME)

clean:
	$(RM) $(NAME)
fclean:
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