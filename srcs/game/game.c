#include "game.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

void game_initialize(game_t *game)
{
	memset(game, 0, sizeof(game_t));
	srand(time(NULL));
}
