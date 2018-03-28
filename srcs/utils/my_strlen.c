#include "utils.h"

size_t my_strlen(const char *str)
{
	size_t len = 0;

	if (!str)
		return 0;
	while (str[len])
		++len;
	return len;
}
