#include "test.h"

// Test with 1 str
static void test_1(char *str, int var_1, int test_num)
{
	char *buffer_exp, *buffer_res;
	buffer_exp = calloc(100, sizeof(char));
	buffer_res = calloc(100, sizeof(char));
	if (!(buffer_exp && buffer_res))
		return ;

	int	exp_file = open("exp.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
	int	res_file = open("res.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);

	// Save current stdout
	int	saved_stdout = dup(STDOUT_FILENO);

	// Redirect from stdout to exp.txt
	dup2(exp_file, STDOUT_FILENO);
	printf(str, var_1);
	fflush(stdout);

	// Redicect from exp.txt to res.txt
	dup2(res_file, STDOUT_FILENO);
	ft_printf(str, var_1);

	// Restore old stdout
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);

    lseek(exp_file, 0, SEEK_SET);
    lseek(res_file, 0, SEEK_SET);

	// Read size - 1 from files to buffs
	int exp_len = read(exp_file, buffer_exp, 100);
	int res_len = read(res_file, buffer_res, 100);

	if(exp_len == res_len && strcmp(buffer_exp, buffer_res) == 0)
	{
		printf("test_num_hex %d passed\n", test_num);
		printf("exp:%s\n", buffer_exp);
		printf("res:%s\n", buffer_res);
		fflush(stdout);
	}
	else
	{
		printf("test_num_hex %d ---FAILED---\n", test_num);
		printf("exp:%s!=res:%s\n", buffer_exp, buffer_res);
		fflush(stdout);
	}

	close(exp_file);
	close(res_file);

	free(buffer_exp);
	free(buffer_res);
}

// Test with 2 strs
static void test_2(char *str, int var_1, int var_2, int test_num)
{
	char *buffer_exp, *buffer_res;
	buffer_exp = calloc(100, sizeof(char));
	buffer_res = calloc(100, sizeof(char));

	int	exp_file = open("exp.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
	int	res_file = open("res.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);

	// Save current stdout
	int	saved_stdout = dup(STDOUT_FILENO);

	// Redirect from stdout to exp.txt
	dup2(exp_file, STDOUT_FILENO);
	printf(str, var_1, var_2);
	fflush(stdout);

	// Redicect from exp.txt to res.txt
	dup2(res_file, STDOUT_FILENO);
	ft_printf(str, var_1, var_2);

	// Restore old stdout
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);

    lseek(exp_file, 0, SEEK_SET);
    lseek(res_file, 0, SEEK_SET);

	// Read size - 1 from files to buffs
	int exp_len = read(exp_file, buffer_exp, 100);
	int res_len = read(res_file, buffer_res, 100);

	if(exp_len == res_len && strcmp(buffer_exp, buffer_res) == 0)
	{
		printf("test_num_hex %d passed\n", test_num);
		printf("exp:%s\n", buffer_exp);
		printf("res:%s\n", buffer_res);
		fflush(stdout);
	}
	else
	{
		printf("test_num_hex %d ---FAILED---\n", test_num);
		printf("exp:%s!=res:%s\n", buffer_exp, buffer_res);
		fflush(stdout);
	}

	close(exp_file);
	close(res_file);

	free(buffer_exp);
	free(buffer_res);
}


void	test_num_hex()
{
	write(1, "---num_hex---\n", 14);
	int	counter = 1;
	union argUnion arg1;
	union argUnion arg2;

	arg1.argddigit = 0;
	test_1_param("%x", arg1, counter++);
	arg1.argddigit = INT_MIN;
	test_1_param("%x", arg1, counter++);
	arg1.argddigit = INT_MAX;
	test_1_param("The number is %x", arg1, counter++);

	arg1.argddigit = 21;
	arg2.arglhex = INT_MAX;
	test_2_params("%X and %X", arg1, arg1, counter++);

	arg1.argddigit = INT_MAX;
	arg2.arglhex = -5081;
	test_2_params("%X and %X", arg1, arg1, counter++);

	write(1, "\n", 1);
}
