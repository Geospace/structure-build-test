CC := clang
CPPFLAGS += -I./includes/
CFLAGS += -Wall -Wextra -pedantic -std=gnu11
LDFLAGS +=

MAKE := make

NAME = my_guess

SRCS = srcs/my_guess.c \
			 srcs/utils/my_strlen.c \
			 srcs/utils/printers.c \
			 srcs/utils/my_strtoi.c \
			 srcs/args/arg_parser.c \
			 srcs/game/game.c \
			 srcs/game/game_loop.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(NAME)

tests: all
	$(MAKE) -C ./tests/ fclean
	$(MAKE) -C ./tests/
	$(MAKE) -C ./tests/ run

clean:
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C ./tests/ fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re tests
