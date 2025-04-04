CC := cc
CFLAGS := -Wall -Wextra -Werror

NAME := philo

SRC := main.c init.c routine.c monitor.c monitor_utils.c threads.c utils.c cleanup.c utils_str.c
OBJ := $(SRC:.c=.o)

# Colors for Output
GREEN := \033[0;32m
YELLOW := \033[0;33m
RESET := \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)  # Added `-o` before `$(NAME)`
	@echo "$(GREEN)Philosophers compiled successfully.$(RESET)"

%.o: %.c philo.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "$(YELLOW)Cleaned object files.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)Cleaned all files.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
