# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 12:10:35 by rmei              #+#    #+#              #
#    Updated: 2025/06/01 11:50:24 by rmei             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# Directories
SRC_DIR = src
OBJ_DIR = obj

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Source and Object Files
SRCS = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	echo "Cleaning libft.a object files..."
	@rm -f $(OBJS)

fclean: clean
	echo "Cleaning $(NAME)..."
	@rm -f $(NAME)

re: fclean all
