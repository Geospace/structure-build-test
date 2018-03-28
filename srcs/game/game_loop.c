#include "game.h"
#include "utils.h"
#include "status.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

comparison_t game_eval_user_guess(const game_t *game, size_t guess)
{
	if (guess > game->to_guess)
		return LOWER;
	if (guess < game->to_guess)
		return GREATER;
	return EQUAL;
}

void game_generate_guess(game_t *game)
{
	size_t min = game->args.min;
	size_t max = game->args.max;

	game->to_guess = rand() % (max + 1 - min) + min;
}

int32_t game_loop(game_t *game)
{
	size_t guess = 0;

	game_generate_guess(game);
	for (;;) {
		my_putstr("What is your guess ? ");
		if (scanf("%lu", &guess) <= SUCCESS) {
			my_putstr("\n");
			return FAILURE;
		}
		switch (game_eval_user_guess(game, guess)) {
			case LOWER:
				my_putstr("Lower !\n");
				break;
			case GREATER:
				my_putstr("Greater !\n");
				break;
			case EQUAL:
				my_putstr("You got it !\n");
				return SUCCESS;
		}
	}
}
