NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

IDIR = includes
LIBFT = $(IDIR)/QuoicouLibft/libft.a

DIR = srcs
SRCS = $(DIR)/*.c
OBJS = $(SRCS:.c=.o)

UP = \033[1A
ERASE = \033[0J

all : QuoicouLibft $(NAME)

QuoicouLibft:
	@make --silent -C $(IDIR)/QuoicouLibft

$(NAME): $(SRCS) $(MANDATORY)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIBFT)
	@echo "\033[1;32m    Made PushSwap\033[0m"

clean:
	@make --silent fclean -C $(IDIR)/QuoicouLibft

fclean:
	@if [ -f $(NAME) ]; then \
			make --silent fclean_no_check; \
	fi

fclean_no_check: clean
	@rm -f $(NAME)
	@echo "\033[1;31m    PushSwap crampted\033[0m"

re : fclean all

.PHONY: QuoicouLibft clean fclean re all