#include "test.h"

// Test with 1 int
static void test_1(char *str, int var_1, int test_num)
{
	char *buffer_exp, *buffer_res;
	buffer_exp = calloc(1000, sizeof(char));
	buffer_res = calloc(1000, sizeof(char));

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
	int exp_len = read(exp_file, buffer_exp, 1000);
	int res_len = read(res_file, buffer_res, 1000);

	if(exp_len == res_len && strcmp(buffer_exp, buffer_res) == 0)
	{
		printf("test_int %d passed\n", test_num);
		printf("exp:%s\n", buffer_exp);
		printf("res:%s\n", buffer_res);
		fflush(stdout);
	}
	else
	{
		printf("test_int %d ---FAILED---\n", test_num);
		printf("exp:%s!=res:%s\n", buffer_exp, buffer_res);
		fflush(stdout);
	}

	close(exp_file);
	close(res_file);

	free(buffer_exp);
	free(buffer_res);
}

// Test with 2 ints
static void test_2(char *str, int var_1, int var_2, int test_num)
{
	char *buffer_exp, *buffer_res;
	buffer_exp = calloc(1000, sizeof(char));
	buffer_res = calloc(1000, sizeof(char));

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
	int exp_len = read(exp_file, buffer_exp, 1000);
	int res_len = read(res_file, buffer_res, 1000);

	if(exp_len == res_len && strcmp(buffer_exp, buffer_res) == 0)
	{
		printf("test_int %d passed\n", test_num);
		printf("exp:%s\n", buffer_exp);
		printf("res:%s\n", buffer_res);
		fflush(stdout);
	}
	else
	{
		printf("test_int %d ---FAILED---\n", test_num);
		printf("exp:%s!=res:%s\n", buffer_exp, buffer_res);
		fflush(stdout);
	}

	close(exp_file);
	close(res_file);

	free(buffer_exp);
	free(buffer_res);
}

void	test_int()
{
	write(1, "---int---\n", 10);
	int counter = 1;
	union argUnion arg1;
	union argUnion arg2;


	arg1.argddigit = 0;
	test_1_param("%i", arg1, counter++);

	arg1.argddigit = INT_MAX;
	test_1_param("num = %i", arg1, counter++);

	arg1.argddigit = INT_MIN;
	test_1_param("num = %i", arg1, counter++);

	arg1.argddigit = 0;
	arg2.argddigit = 1;
	test_2_params("num1 = %i num2 = %i", arg1, arg2, counter++);

	arg1.argddigit = -215;
	arg2.argddigit = 569;
	test_2_params("%iHell%io world", arg1, arg2, counter++);
	write(1, "\n", 1);

}
