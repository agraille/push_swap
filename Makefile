# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 15:02:53 by agraille          #+#    #+#              #
#    Updated: 2024/12/04 10:49:35 by agraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
HEADER = push_swap.h
SRC =./main.c\
	./push_swap.c

OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(NAME) $(OBJ)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I . -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all re fclean clean
