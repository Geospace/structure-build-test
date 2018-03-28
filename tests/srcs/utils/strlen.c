#include <criterion/criterion.h>
#include "utils.h"

Test(strlen, valid_string) {
	const char *str = "valid string";
	cr_assert(my_strlen(str) == strlen(str));
}

// String should not be changed
Test(strlen, const_string) {
	const char *str = "valid string";
	char *copy = strdup(str);

	cr_assert(my_strlen(str) == strlen(str));
	cr_assert_str_eq(str, copy);

	free(copy);
}

Test(strlen, empty_string) {
	const char *str = "";
	cr_assert(my_strlen(str) == strlen(str));
}

// This should either crash or return 0
Test(strlen, null_ptr, .signal = SIGSEGV) {
	const char *str = NULL;
	cr_assert(my_strlen(str) == strlen(str));
}

// This should crash
Test(strlen, invalid_ptr, .signal = SIGSEGV) {
	const ptrdiff_t str = 0xdeadbeef;
	cr_assert(my_strlen((const char *)str) == strlen((const char *)str));
}
