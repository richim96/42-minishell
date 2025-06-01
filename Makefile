# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/01 11:50:45 by rmei              #+#    #+#              #
#    Updated: 2025/06/01 11:50:49 by rmei             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = src/lib/libft

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -I$(LIBFT_DIR)/include
LDFLAGS = -L$(LIBFT_DIR) -lft -lreadline

# Source and Object Files
SRCS = $(shell find $(SRC_DIR) -name '*.c' -not -path '*/lib/*')
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_DIR)/libft.a:
	echo "Making libft in $(LIBFT_DIR)..."
	@$(MAKE) -sC $(LIBFT_DIR)

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	echo "Cleaning $(NAME) object files..."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	echo "Cleaning $(NAME)..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus 
