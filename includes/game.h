#pragma once

#include "args.h"
#include <stdint.h>

typedef enum {
	EQUAL,
	LOWER,
	GREATER
} comparison_t;

typedef struct {
	args_t args;
	size_t to_guess;
} game_t;

void game_initialize(game_t *game);
int32_t game_loop(game_t *game);
void game_generate_guess(game_t *game);
comparison_t game_eval_user_guess(const game_t *game, size_t guess);
