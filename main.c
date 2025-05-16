#include "test.h"

void test_1_param(char *str, union argUnion var_1, int test_num)
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
	int exp_return = printf(str, var_1);
	fflush(stdout);

	// Redicect from exp.txt to res.txt
	dup2(res_file, STDOUT_FILENO);
	int res_return = ft_printf(str, var_1);

	// Restore old stdout
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);

    lseek(exp_file, 0, SEEK_SET);
    lseek(res_file, 0, SEEK_SET);

	// Read size - 1 from files to buffs
	int exp_len = read(exp_file, buffer_exp, 100);
	int res_len = read(res_file, buffer_res, 100);

	if(exp_len == res_len && strcmp(buffer_exp, buffer_res) == 0 && exp_return == res_return)
	{
		printf("test %d passed\n", test_num);
		printf("exp:%s\n", buffer_exp);
		printf("res:%s\n", buffer_res);
		printf("exp return: %d\n", exp_return);
		printf("res return: %d\n", res_return);

		fflush(stdout);
	}
	else
	{
		printf("%stest %d ---FAILED---\n%s", KRED, test_num, KNRM);
		printf("exp:%s!=res:%s\n", buffer_exp, buffer_res);
		printf("exp return: %d\n", exp_return);
		printf("res return: %d\n", res_return);
		fflush(stdout);
	}

	close(exp_file);
	close(res_file);

	free(buffer_exp);
	free(buffer_res);
}

// Test with 2 chars
void test_2_params(char *str, union argUnion var_1, union argUnion var_2, int test_num)
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
	int exp_return = printf(str, var_1, var_2);
	fflush(stdout);

	// Redicect from exp.txt to res.txt
	dup2(res_file, STDOUT_FILENO);
	int res_return = ft_printf(str, var_1, var_2);

	// Restore old stdout
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);

    lseek(exp_file, 0, SEEK_SET);
    lseek(res_file, 0, SEEK_SET);

	// Read size - 1 from files to buffs
	int exp_len = read(exp_file, buffer_exp, 100);
	int res_len = read(res_file, buffer_res, 100);



	if(exp_len == res_len && strcmp(buffer_exp, buffer_res) == 0 && exp_return == res_return)
	{
		printf("test %d passed\n", test_num);
		printf("exp:%s\n", buffer_exp);
		printf("res:%s\n", buffer_res);
		printf("exp return: %d\n", exp_return);
		printf("res return: %d\n", res_return);

		fflush(stdout);
	}
	else
	{
		printf("%stest %d ---FAILED---\n%s", KRED, test_num, KNRM);
		printf("exp:%s!=res:%s\n", buffer_exp, buffer_res);
		printf("exp return: %d\n", exp_return);
		printf("res return: %d\n", res_return);
		fflush(stdout);
	}


	close(exp_file);
	close(res_file);

	free(buffer_exp);
	free(buffer_res);
}

int	main()
{
	test_no_conversion();
	test_char();
	test_string();
	test_num_hex();
	mixed_cases();
	test_int();
	test_pointer();

	return (0);
}
