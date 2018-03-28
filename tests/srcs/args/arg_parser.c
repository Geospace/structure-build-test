#include <criterion/criterion.h>
#include "args.h"
#include "status.h"

Test(args_parse, valid_params) {
	args_t args;

	const char *const argv[] = {
		"hello", "1", "4"
	};
	cr_assert(args_parse(&args, 3, argv) == SUCCESS);
	cr_assert(args.min == 1);
	cr_assert(args.max == 4);
}

Test(args_parse, not_enough_params) {
	args_t args;

	const char *const argv[] = {
		"hello", "1"
	};
	cr_assert(args_parse(&args, 2, argv) == FAILURE);
}

Test(args_parse, invalid_first_param) {
	args_t args;

	const char *const argv[] = {
		"hello", "du", "2"
	};
	cr_assert(args_parse(&args, 3, argv) == FAILURE);
}

Test(args_parse, invalid_second_param) {
	args_t args;

	const char *const argv[] = {
		"hello", "1", "du"
	};
	cr_assert(args_parse(&args, 3, argv) == FAILURE);
}

Test(args_parse, invalid_params) {
	args_t args;

	const char *const argv[] = {
		"hello", "ll", ""
	};
	cr_assert(args_parse(&args, 3, argv) == FAILURE);
}
