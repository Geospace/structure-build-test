#include <criterion/criterion.h>
#include <criterion/parameterized.h>
#include "utils.h"

ParameterizedTestParameters(isnum, valid_entry) {
	static char params[] = {
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
	};
	size_t nb_params = sizeof (params) / sizeof (char);
	return cr_make_param_array(char, params, nb_params);
}

ParameterizedTest(char *param, isnum, valid_entry) {
	cr_assert(my_is_num(*param) == true);
}

Test(isnum, invalid_entry) {
	cr_assert(my_is_num('%') == false);
	cr_assert(my_is_num('@') == false);
	cr_assert(my_is_num('L') == false);
	cr_assert(my_is_num('D') == false);
	cr_assert(my_is_num('c') == false);
	cr_assert(my_is_num('|') == false);
	cr_assert(my_is_num('(') == false);
	cr_assert(my_is_num('b') == false);
	cr_assert(my_is_num('^') == false);
}
