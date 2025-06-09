# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/01 11:50:45 by rmei              #+#    #+#              #
#    Updated: 2025/06/09 19:58:38 by rmei             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -I$(LIBFT_DIR)/include
LDFLAGS = -L$(LIBFT_DIR) -lft -lreadline

# Directory tree
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = lib/libft

PARSING_SRCS = lexer.c operators.c quotes.c tokens.c
PARSING_SRCS := $(addprefix parsing/, ${PARSING_SRCS})
COMMAND_SRCS = ft_cd.c ft_echo.c ft_env.c ft_exit.c ft_export.c ft_pwd.c ft_unset.c
COMMAND_SRCS := $(addprefix commands/, ${COMMAND_SRCS})

SRCS = main.c signals.c $(PARSING_SRCS) $(COMMAND_SRCS)
SRCS := $(addprefix $(SRC_DIR)/, ${SRCS})
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
.PHONY: all libft end clean fclean re bonus 

all: libft $(NAME) end

$(NAME): $(OBJS) 
	@$(call log_info, "Linking $(NAME)...")
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@$(call log_info, "Created $(NAME) executable")

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(call log_info, "Compiling $< to $@...")
	@$(CC) $(CFLAGS) -c $< -o $@

libft:
	@$(call log_info, "Calling libft Makefile...")
	@$(MAKE) -sC $(LIBFT_DIR)

end:
	@$(call log_info, "Everything is done!")

clean:
	@$(call log_info, "Calling libft Makefile...")
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(call log_info, "Deleting $(NAME) object files if any...")
	@rm -rf $(OBJ_DIR)

fclean:
	@$(call log_info, "Calling libft Makefile...")
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	@$(call log_info, "Deleting object files if any...")
	@rm -rf $(OBJ_DIR)
	@$(call log_info, "Deleting ´$(NAME)´ executable if present...")
	@rm -f $(NAME)

re: fclean all
