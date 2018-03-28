#include <criterion/criterion.h>
#include "utils.h"
#include "status.h"

Test(strtoi, valid_number) {
	const char *str = "242490";
	size_t result = 0;

	cr_assert(try_strtoi(str, &result) == SUCCESS);
	cr_assert(result == 242490);
}

Test(strtoi, empty_string) {
	const char *str = "";
	size_t result = 0;

	cr_assert(try_strtoi(str, &result) == FAILURE);
	cr_assert(result == 0);
}

Test(strtoi, invalid_string) {
	const char *str = "kdjfksdjf";
	size_t result = 0;

	cr_assert(try_strtoi(str, &result) == FAILURE);
	cr_assert(result == 0);
}

Test(strtoi, invalid_string_end) {
	const char *str = "23241kdjfksdjf";
	size_t result = 0;

	cr_assert(try_strtoi(str, &result) == SUCCESS);
	cr_assert(result == 23241);
}
