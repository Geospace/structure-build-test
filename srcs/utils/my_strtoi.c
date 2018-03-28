#include "utils.h"
#include "status.h"

static const size_t BASE_DECI = 10;

bool my_is_num(char c)
{
  return (c >= '0' && c <= '9');
}

int32_t try_strtoi(const char *str, size_t *result)
{
  size_t fact;
  const char *end;
  const char *start;

  fact = 1;
  *result = 0;
  start = str;
  while (my_is_num(*str))
    str++;
  end = str;
  if (end == start)
    return FAILURE;
  while (start != end) {
    *result += (fact * (*(--end) - '0'));
    fact *= BASE_DECI;
  }
  return SUCCESS;
}
