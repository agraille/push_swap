# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 15:02:53 by agraille          #+#    #+#              #
#    Updated: 2024/12/15 23:13:36 by agraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
INCLUDE= Push_swap/
BONUS_INCLUDE = Checker_bonus/
SRC = $(INCLUDE)main.c \
      $(INCLUDE)push_swap.c \
      $(INCLUDE)push_swap2.c \
      $(INCLUDE)push_swap3.c \
      $(INCLUDE)push_swap_utils.c \
      $(INCLUDE)push_swap_utils2.c \
      $(INCLUDE)ft_split_int.c
	  
BONUS_SRC = $(BONUS_INCLUDE)checker_bonus.c \
            $(BONUS_INCLUDE)checker_main_bonus.c \
            $(BONUS_INCLUDE)checker_utils_bonus.c \
            $(BONUS_INCLUDE)checker_utils2_bonus.c \
            $(BONUS_INCLUDE)checker_utils3_bonus.c \
            $(BONUS_INCLUDE)checker_utils4_bonus.c \
            $(BONUS_INCLUDE)gnl_bonus.c \
            $(BONUS_INCLUDE)gnl_utils_bonus.c
			
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
NAME = push_swap
BONUS_NAME = checker
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║   Compilation Succes! ✅  ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

bonus: $(NAME) .bonus
	@echo "$(GREEN)╔═════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║   Compilation Bonus Succes! ✅  ║$(RESET)"
	@echo "$(GREEN)╚═════════════════════════════════╝$(RESET)"

.bonus: $(BONUS_OBJ)
	$(NAME) $(BONUS_OBJ) -o $(BONUS_NAME)
	@touch Checker_bonus/.bonus
	
clean :
	@rm -f $(OBJ) $(BONUS_OBJ) .bonus
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║        Clean OK! 🧽       ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

fclean :
	@rm -f $(OBJ) $(NAME) $(BONUS_NAME) $(BONUS_OBJ) .bonus
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║        Fclean OK! 🪣       ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"


re : fclean all

.PHONY : all bonus re fclean clean .bonus
