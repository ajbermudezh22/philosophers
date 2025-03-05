# Compiler and Flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror -pthread

# Project Name
NAME := philo

# Source and Object Files
SRC := main.c init.c routine.c monitor.c threads.c utils.c
OBJ := $(SRC:.c=.o)

# Libft Settings
LIBFT_DIR := libft
LIBFT_A := $(LIBFT_DIR)/libft.a
LIBFT_INC := -I$(LIBFT_DIR)
LIBFT_LINK := -L$(LIBFT_DIR) -lft

# Colors for Output
GREEN := \033[0;32m
YELLOW := \033[0;33m
RESET := \033[0m

# Compilation Rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_LINK)
	@echo "$(GREEN)Philosophers compiled successfully.$(RESET)"

# Compile .c to .o
%.o: %.c philo.h
	@$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@

# Compile Libft if needed
$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft compiled successfully.$(RESET)"

# Cleanup Rules
clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(YELLOW)Cleaned object files.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(YELLOW)Cleaned all files.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
