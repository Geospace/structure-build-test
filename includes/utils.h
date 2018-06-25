#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <signal.h>

void my_putstr(const char *str);
void my_putstr_error(const char *str);
size_t my_strlen(const char *str);
bool my_is_num(char c);
int32_t try_strtoi(const char *str, size_t *result);
