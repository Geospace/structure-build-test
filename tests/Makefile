CC := clang
CPPFLAGS += -I../includes/
CFLAGS += -Wall -Wextra -pedantic -std=gnu11
LDFLAGS += -lcriterion

NAME = tests

SRCS = srcs/utils/strlen.c \
			 srcs/utils/strtoi.c \
			 srcs/utils/isnum.c \
			 srcs/args/arg_parser.c \
			 srcs/args/args_check_validity.c \
			 srcs/game/game_eval_user_guess.c \
			 srcs/game/game_generate_guess.c \
			 ../srcs/utils/my_strlen.c \
			 ../srcs/utils/printers.c \
			 ../srcs/utils/my_strtoi.c \
			 ../srcs/args/arg_parser.c \
			 ../srcs/game/game.c \
			 ../srcs/game/game_loop.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(NAME)

run:
	@ ./$(NAME) --verbose

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean run re
