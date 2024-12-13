# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 15:02:53 by agraille          #+#    #+#              #
#    Updated: 2024/12/13 14:27:04 by agraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
INCLUDE= Push_swap/
SRC = $(INCLUDE)main.c \
      $(INCLUDE)push_swap.c \
      $(INCLUDE)push_swap2.c \
      $(INCLUDE)push_swap3.c \
      $(INCLUDE)push_swap_utils.c \
      $(INCLUDE)push_swap_utils2.c \
      $(INCLUDE)ft_split_int.c

OBJ = $(SRC:.c=.o)
NAME = push_swap
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║   Compilation Succes! ✅  ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"
	
clean :
	rm -f $(OBJ)
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║        Clean OK! 🧽       ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all re fclean clean
