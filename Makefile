NAME = push_swap
CHECKER = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

IDIR = includes
LIBFT = $(IDIR)/QuoicouLibft/libft.a

DIR = srcs
EDIR = $(DIR)/errors_handling
ODIR = $(DIR)/operations
SDIR = $(DIR)/sort
UDIR = $(DIR)/utils

SRCS = $(DIR)/main.c \
		$(EDIR)/errors_handling_and_init.c $(EDIR)/errors_handling_utils.c \
		$(ODIR)/ops_rotate.c $(ODIR)/ops_rrr.c $(ODIR)/ops_swap_push.c $(ODIR)/st_operations.c \
		$(SDIR)/sort.c $(SDIR)/sort_init_a.c $(SDIR)/sort_init_b.c $(SDIR)/sort_move.c \
		$(UDIR)/string_utils.c $(UDIR)/st_utilis_2.c $(UDIR)/st_utils.c
BSRCS = $(DIR)/checker.c \
		$(EDIR)/errors_handling_and_init.c $(EDIR)/errors_handling_utils.c $(EDIR)/errors_handling_checker.c \
		$(ODIR)/ops_rotate.c $(ODIR)/ops_rrr.c $(ODIR)/ops_swap_push.c $(ODIR)/st_operations.c \
		$(SDIR)/sort.c $(SDIR)/sort_init_a.c $(SDIR)/sort_init_b.c $(SDIR)/sort_move.c \
		$(UDIR)/string_utils.c $(UDIR)/st_utilis_2.c $(UDIR)/st_utils.c

UP = \033[1A
ERASE = \033[0J

all : QuoicouLibft $(NAME)

QuoicouLibft:
	@make --silent -C $(IDIR)/QuoicouLibft

$(NAME):
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIBFT)
	@echo "\033[1;32m  ● Made PushSwap\033[0m"

$(CHECKER):
	@$(CC) $(CFLAGS) $(BSRCS) -o $(CHECKER) $(LIBFT)
	@echo "\033[1;32m  ● Made Checker\033[0m"

bonus: 
	@make --silent $(QuoicouLibft)
	@make --silent $(CHECKER)

clean:
	@rm -f $(NAME)
	@rm -f $(CHECKER)
	@make --silent fclean -C $(IDIR)/QuoicouLibft

fclean:
	@rm -f $(CHECKER)
	@if [ -f $(NAME) ]; then \
			make --silent fclean_no_check; \
	fi

fclean_no_check: clean
	@rm -f $(NAME)
	@echo "\033[1;31m    PushSwap crampted\033[0m"

re : fclean all

.PHONY: QuoicouLibft clean fclean re all