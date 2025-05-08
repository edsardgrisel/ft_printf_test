/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_no_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsardgrisel <edsardgrisel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:17:33 by edsardgrise       #+#    #+#             */
/*   Updated: 2025/05/08 18:00:08 by edsardgrise      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "test.h"

// with zero variadic vars
static void test_0(char *str, int test_num)
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
	printf("%s", str);
	fflush(stdout);

	// Redicect from exp.txt to res.txt
	dup2(res_file, STDOUT_FILENO);
	ft_printf(str);

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
		printf("test_no_conversion %d passed\n", test_num);
		printf("exp:%s\n", buffer_exp);
		printf("res:%s\n", buffer_res);
		fflush(stdout);
	}
	else
	{
		printf("test_no_conversion %d ---FAILED---\n", test_num);
		printf("exp:%s!=res:%s", buffer_exp, buffer_res);
		fflush(stdout);
	}

	close(exp_file);
	close(res_file);

	free(buffer_exp);
	free(buffer_res);
}

void	test_no_conversion()
{
	int	counter = 1;
	test_0("", counter++);
	test_0("world", counter++);
	write(1, "\n", 1);

}