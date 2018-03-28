#pragma once

#include <stddef.h>
#include <stdint.h>

typedef struct {
	size_t min;
	size_t max;
} args_t;

int32_t args_check_validity(const args_t *args);
int32_t args_parse(args_t *args, int argc, const char *const argv[]);
