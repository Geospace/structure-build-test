#include "game.h"
#include "status.h"
#include "utils.h"
#include <stdlib.h>

static const char *INVALID_ARGS = "Invalid arguments.\n";

int my_guess(int argc, const char *const argv[])
{
	game_t game;

	game_initialize(&game);
	if (args_parse(&game.args, argc, argv) == FAILURE ||
			args_check_validity(&game.args) == FAILURE) {
		my_putstr_error(INVALID_ARGS);
		return FAILURE;
	}
	return game_loop(&game);
}

int main(int argc, const char *const argv[]) {
	return my_guess(argc, argv);
}
