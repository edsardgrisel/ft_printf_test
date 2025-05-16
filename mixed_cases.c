#include "test.h"

// // Test with 2 chars
// static void test_mixed_string_hex(char *str, char var_1, char *var_2, int var_3, int test_num)
// {
// 	char *buffer_exp, *buffer_res;
// 	buffer_exp = calloc(100, sizeof(char));
// 	buffer_res = calloc(100, sizeof(char));

// 	int	exp_file = open("exp.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
// 	int	res_file = open("res.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);

// 	// Save current stdout
// 	int	saved_stdout = dup(STDOUT_FILENO);

// 	// Redirect from stdout to exp.txt
// 	dup2(exp_file, STDOUT_FILENO);
// 	printf(str, var_1, var_2, var_3);
// 	fflush(stdout);

// 	// Redicect from exp.txt to res.txt
// 	dup2(res_file, STDOUT_FILENO);
// 	ft_printf(str, var_1, var_2, var_3);

// 	// Restore old stdout
// 	dup2(saved_stdout, STDOUT_FILENO);
// 	close(saved_stdout);

//     lseek(exp_file, 0, SEEK_SET);
//     lseek(res_file, 0, SEEK_SET);

// 	// Read size - 1 from files to buffs
// 	int exp_len = read(exp_file, buffer_exp, 100);
// 	int res_len = read(res_file, buffer_res, 100);

// 	if(exp_len == res_len && strcmp(buffer_exp, buffer_res) == 0)
// 	{
// 		printf("test_mixed %d passed\n", test_num);
// 		printf("exp:%s\n", buffer_exp);
// 		printf("res:%s\n", buffer_res);
// 		fflush(stdout);
// 	}
// 	else
// 	{
// 		printf("test_mixed %d ---FAILED---\n", test_num);
// 		printf("exp:%s!=res:%s\n", buffer_exp, buffer_res);
// 		fflush(stdout);
// 	}

// 	close(exp_file);
// 	close(res_file);

// 	free(buffer_exp);
// 	free(buffer_res);
// }

void	mixed_cases()
{
	write(1, "---mixed---\n", 12);
	union argUnion arg1;
	union argUnion arg2;
	int counter = 1;
	char *str = "a";

	arg1.argpointer = "HELLo";
	arg2.arglhex = -35489;
	test_2_params("String is:%s, hex is:%x", arg1, arg2, counter++);

	arg1.argddigit = INT_MIN;
	arg2.argchar = 'p';

	test_2_params("Char is:%c, hex is:%X%%", arg2, arg1, counter++);
	write(1, "\n", 1);

}
