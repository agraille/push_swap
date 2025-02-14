# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 15:02:53 by agraille          #+#    #+#              #
#    Updated: 2025/02/14 08:20:35 by agraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all bonus re fclean clean .bonus

NAME = push_swap
BONUS_NAME=checker
CC=cc
CFLAGS=-Wall -Wextra -Werror -g3
SRC = srcs/main.c\
      srcs/push_swap/push_swap.c\
      srcs/push_swap/push_swap2.c\
      srcs/push_swap/push_swap3.c\
      srcs/push_swap/push_swap_utils.c\
      srcs/push_swap/push_swap_utils2.c\
      srcs/utils/ft_split_int.c
BONUS_SRC = srcs/bonus/checker_bonus.c \
            srcs/bonus/checker_main_bonus.c \
            srcs/bonus/checker_utils_bonus.c \
            srcs/bonus/checker_utils2_bonus.c \
            srcs/bonus/checker_utils3_bonus.c \
            srcs/bonus/checker_utils4_bonus.c \
            srcs/utils/gnl_bonus.c \
            srcs/utils/gnl_utils_bonus.c

OBJ_DIR = obj
OBJ	= $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))
BONUS_OBJ = $(addprefix $(OBJ_DIR)/,$(BONUS_SRC:%.c=%.o))
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║   Compilation Succes! ✅  ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)
	@echo "$(GREEN)╔═════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║   Compilation Bonus Succes! ✅  ║$(RESET)"
	@echo "$(GREEN)╚═════════════════════════════════╝$(RESET)"

$(OBJ_DIR)/%.o: %.c Makefile ./includes/push_swap.h ./includes/checker_bonus.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I . -c $< -o $@


clean :
	@rm -rf $(OBJ) $(BONUS_OBJ) $(OBJ_DIR)/
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║        Clean OK! 🧽       ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

fclean :
	@rm -rf $(NAME) $(OBJ) $(OBJ_DIR) $(BONUS_NAME) $(BONUS_OBJ)
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║        Fclean OK! 🪣       ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

re : fclean all
