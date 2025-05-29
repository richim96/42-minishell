NAME = minishell

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -Isrc/lib/libft/include
LDFLAGS = -Lsrc/lib/libft -lft -lreadline

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = src/lib/libft # Adjusted path to your libft

# Source Files: Automatically find all .c files in SRC_DIR and its subdirectories
# Excludes any files in */lib/* or *_bonus.c patterns
SRCS = $(shell find $(SRC_DIR) -name '*.c' -not -path '*/lib/*' -not -name '*_bonus.c')

# Object Files: Generate .o paths in OBJ_DIR based on SRCS
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

# Pattern rule to compile .c files from SRC_DIR (and subdirs) to .o files in OBJ_DIR (and mirrored subdirs)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D) # Create subdirectory in obj if it doesn't exist
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build libft.a by calling its own Makefile
$(LIBFT_DIR)/libft.a:
	@echo "Making libft in $(LIBFT_DIR)..."
	@$(MAKE) -sC $(LIBFT_DIR)

clean:
	@echo "Cleaning object files..."
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Cleaning $(NAME)..."
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

# Phony targets
.PHONY: all clean fclean re bonus 
