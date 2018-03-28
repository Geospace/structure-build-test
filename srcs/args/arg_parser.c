#include "args.h"
#include "status.h"
#include "utils.h"

static const size_t MAX_GUESS = 100;

int32_t args_check_validity(const args_t *args)
{
	if (args->min >= args->max)
		return FAILURE;
	if (args->max > MAX_GUESS)
		return FAILURE;
	return SUCCESS;
}

int32_t args_parse(args_t *args, int argc, const char *const argv[])
{
	if (argc != 3)
		return FAILURE;

	if (try_strtoi(*(argv + 1), &args->min) != SUCCESS ||
			try_strtoi(*(argv + 2), &args->max) != SUCCESS) {
		return FAILURE;
	}
	return SUCCESS;
}
