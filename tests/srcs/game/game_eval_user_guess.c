#include <criterion/criterion.h>
#include "game.h"

Test(game_eval_user_guess, lower) {
	game_t game;
	game.to_guess = 10;

	cr_assert(game_eval_user_guess(&game, 20) == LOWER);
}

Test(game_eval_user_guess, greater) {
	game_t game;
	game.to_guess = 10;

	cr_assert(game_eval_user_guess(&game, 2) == GREATER);
}

Test(game_eval_user_guess, equal) {
	game_t game;
	game.to_guess = 10;

	cr_assert(game_eval_user_guess(&game, 10) == EQUAL);
}
