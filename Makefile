# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kube <kube@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/14 02:31:26 by cfeijoo           #+#    #+#              #
#    Updated: 2014/01/07 23:16:03 by kube             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

INCFOLDER = -I./includes -I./libft/includes
LIBFOLDERS = -L./libft/
LIBS = -ltermcap -lft

CC = cc
CFLAGS = -Wall -Wextra -Werror -pedantic

SRC	=	main.c			\
		selector.c		\
		cursor.c		\
		display.c		\
		keyboard.c		\
		draw.c

OSRC = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(INCFOLDER) -c $(SRC)
	$(CC) $(CFLAGS) $(OSRC) $(LIBFOLDERS) $(LIBS) -o $(NAME)

updatelibs:
	cd libft && git pull
	make -C libft re	

clean:
	rm -f $(OSRC)

fclean: clean
	rm -f $(NAME)

re: fclean all
