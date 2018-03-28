#include <criterion/criterion.h>
#include "game.h"

Test(game_generate_guess, in_bounds) {
	game_t game;

	game_initialize(&game);
	game.args.min = 1;
	game.args.max = 100;

	for (size_t i = 0; i < game.args.max * 100; i++) {
		game_generate_guess(&game);
		cr_assert(game.to_guess >= game.args.min);
		cr_assert(game.to_guess <= game.args.max);
	}
}
