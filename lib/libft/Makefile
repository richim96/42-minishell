# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 12:10:35 by rmei              #+#    #+#              #
#    Updated: 2025/06/01 20:57:45 by rmei             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_DIR = src
OBJ_DIR = obj

SRCS = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Logger
LOG = "[libft]"
GREEN = \033[0;32m
BLUE = \033[0;34m
RESET = \033[0m

define log_info
	@echo "$(shell date +"%d-%m-%Y %T") $(GREEN)$(LOG) $(BLUE)INFO$(RESET)$(1)"
endef

# ---- RULES ---- #
.PHONY: all compile-start clean arclean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $@ $^
	@$(call log_info, "Archive for $(NAME) created")

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | compile-start
	@mkdir -p $(@D)
	@cc -Wall -Wextra -Werror -Iinclude -c $< -o $@

compile-start:
	@$(call log_info, "Compiling $(NAME)...")

clean:
	@$(call log_info, "Cleaning $(NAME) object files...")
	@rm -rf $(OBJ_DIR)

arclean:
	@$(call log_info, "Cleaning $(NAME) archive...")
	@rm -f $(NAME)

fclean: clean arclean

re: fclean all
