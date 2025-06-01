# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/01 11:50:45 by rmei              #+#    #+#              #
#    Updated: 2025/06/01 20:55:22 by rmei             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -I$(LIBFT_DIR)/include
LDFLAGS = -L$(LIBFT_DIR) -lft -lreadline

SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = lib/libft

SRCS = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Logger
LOG = "[minishell]"
PURPLE = \033[0;35m
BLUE = \033[0;34m
RESET = \033[0m

define log_info
	@echo "$(shell date +"%d-%m-%Y %T") $(PURPLE)$(LOG) $(BLUE)INFO$(RESET)$(1)"
endef

# ---- RULES ---- #
.PHONY: all libft compile-start clean fclean re bonus 

all: $(NAME)

$(NAME): $(OBJS) libft compile-start
	@$(call log_info, "Linking $(NAME)...")
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@$(call log_info, "Created $(NAME) executable")

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

libft:
	@$(call log_info, "Making libft in $(LIBFT_DIR)/...")
	@$(MAKE) -sC $(LIBFT_DIR)

compile-start:
	@$(call log_info, "Compiling $(NAME)...")

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(call log_info, "Cleaning $(NAME) object files...")
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -sC $(LIBFT_DIR) arclean
	@$(call log_info, "Cleaning $(NAME)...")
	@rm -f $(NAME)

re: fclean all
