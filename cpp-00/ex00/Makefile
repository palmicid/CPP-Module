# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 00:37:39 by pruangde          #+#    #+#              #
#    Updated: 2023/07/19 10:04:30 by pruangde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= megaphone

CC 			= c++
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -std=c++98

RM			= rm -rf

FILE = megaphone.cpp

all:
	$(CC) $(CFLAGS) $(CPPFLAGS) $(FILE) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: fclean all