# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 15:02:53 by agraille          #+#    #+#              #
#    Updated: 2024/12/16 09:11:16 by agraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror -g3
SRC = main.c\
      push_swap.c\
      push_swap2.c\
      push_swap3.c\
      push_swap_utils.c\
      push_swap_utils2.c\
      ft_split_int.c
	  
BONUS_SRC = checker_bonus.c \
            checker_main_bonus.c \
            checker_utils_bonus.c \
            checker_utils2_bonus.c \
            checker_utils3_bonus.c \
            checker_utils4_bonus.c \
            gnl_bonus.c \
            gnl_utils_bonus.c
			
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
NAME = push_swap
BONUS_NAME = checker
DEPS = $(SRC:.c=.d) $(BONUS_SRC:.c=.d)
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

%.o: %.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@

-include $(DEPS)

clean :
	rm -f $(OBJ) $(BONUS_OBJ) $(DEPS)
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║        Clean OK! 🧽       ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

fclean :
	rm -f $(OBJ) $(NAME) $(BONUS_NAME) $(BONUS_OBJ) $(DEPS)
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║        Fclean OK! 🪣       ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"


re : fclean all

.PHONY : all bonus re fclean clean .bonus
