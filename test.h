#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "../ft_printf/libftprintf.h"
#include <limits.h>

union argUnion
{
	char argchar;
	char *argstring;
	void *argpointer;
	int argddigit;
	int argidigit;
	unsigned int argudigit;
	unsigned int arglhex;
	unsigned int arguhex;
};


void test_1_param(char *str, union argUnion var_1, int test_num);
void test_2_params(char *str, union argUnion var_1, union argUnion var_2, int test_num);


void	test_char();
void	test_no_conversion();
void	test_string();
void	test_num_hex();
void	mixed_cases();
void	test_int();

