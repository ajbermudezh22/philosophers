# Compiler and Flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror -pthread

# Project Name
NAME := philosophers

# Source and Object Files
SRC := main.c init.c simulation.c monitor.c utils.c cleanup.c
OBJ := $(SRC:.c=.o)

# Colors for Output
GREEN := \033[0;32m
YELLOW := \033[0;33m
RESET := \033[0m

# Compilation Rules
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)Philosophers project compiled successfully.$(RESET)"

# Compile .c to .o
%.o: %.c philosophers.h
	@$(CC) $(CFLAGS) -c $< -o $@

# Cleanup Rules
clean:
	@rm -f $(OBJ)
	@echo "$(YELLOW)Cleaned object files.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)Cleaned all files.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
