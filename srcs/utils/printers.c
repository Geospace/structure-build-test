#include <unistd.h>
#include "utils.h"

void my_putstr(const char *str)
{
	write(STDOUT_FILENO, str, my_strlen(str));
}

void my_putstr_error(const char *str)
{
	write(STDERR_FILENO, str, my_strlen(str));
}
