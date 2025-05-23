/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:36:34 by edsardgrise       #+#    #+#             */
/*   Updated: 2025/05/16 14:19:27 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

// // Test with 1 str
// static void test_1(char *str, char *c_1, int test_num)
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
// 	printf(str, c_1);
// 	fflush(stdout);

// 	// Redicect from exp.txt to res.txt
// 	dup2(res_file, STDOUT_FILENO);
// 	ft_printf(str, c_1);

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
// 		printf("test_string %d passed\n", test_num);
// 		printf("exp:%s\n", buffer_exp);
// 		printf("res:%s\n", buffer_exp);
// 		fflush(stdout);
// 	}
// 	else
// 	{
// 		printf("test_string %d ---FAILED---\n", test_num);
// 		printf("exp:%s!=res:%s", buffer_exp, buffer_res);
// 		fflush(stdout);
// 	}

// 	close(exp_file);
// 	close(res_file);

// 	free(buffer_exp);
// 	free(buffer_res);
// }

// // Test with 2 strs
// static void test_2(char *str, char *var_1, char *var_2, int test_num)
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
// 	printf(str, var_1, var_2);
// 	fflush(stdout);

// 	// Redicect from exp.txt to res.txt
// 	dup2(res_file, STDOUT_FILENO);
// 	ft_printf(str, var_1, var_2);

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
// 		printf("test_string %d passed\n", test_num);
// 		printf("exp:%s\n", buffer_exp);
// 		printf("res:%s\n", buffer_exp);
// 		fflush(stdout);
// 	}
// 	else
// 	{
// 		printf("test_string %d ---FAILED---\n", test_num);
// 		printf("exp:%s!=res:%s", buffer_exp, buffer_res);
// 		fflush(stdout);
// 	}

// 	close(exp_file);
// 	close(res_file);

// 	free(buffer_exp);
// 	free(buffer_res);
// }


void	test_string()
{
	write(1, "---string---\n", 13);

	union argUnion arg1;
	union argUnion arg2;
	int	counter = 1;


	// arg1.argpointer = NULL;
	// test_1_param("%s", arg1, counter++);

	arg1.argpointer = "world";
	test_1_param("Hello %s", arg1 , counter++);

	arg1.argpointer = "Hello";
	arg2.argpointer = "world";
	test_2_params("%s %s", arg1, arg2, counter++);

	arg1.argpointer = "Hello";
	arg2.argpointer = "world";
	test_2_params("first: %s. second: %s", arg1, arg2, counter++);
	write(1, "\n", 1);
}
