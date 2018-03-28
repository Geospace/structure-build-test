#include <criterion/criterion.h>
#include "args.h"
#include "status.h"

Test(args_check_validity, valid_params) {
	args_t args;

	args.min = 1;
	args.max = 2;
	cr_assert(args_check_validity(&args) == SUCCESS);
}

Test(args_check_validity, equal_params) {
	args_t args;

	args.min = 2;
	args.max = 2;
	cr_assert(args_check_validity(&args) == FAILURE);
}

Test(args_check_validity, invalid_params) {
	args_t args;

	args.min = 3;
	args.max = 2;
	cr_assert(args_check_validity(&args) == FAILURE);
}

Test(args_check_validity, way_too_big_params) {
	args_t args;

	args.min = 3;
	args.max = 2;
	cr_assert(args_check_validity(&args) == FAILURE);
}
