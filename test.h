#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "../ft_printf/libftprintf.h"
#include <limits.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

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
void	test_pointer();


