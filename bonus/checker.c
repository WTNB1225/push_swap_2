/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:27:48 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/01 22:23:48 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	free_all_memory(t_stack *stack_a, t_stack *stack_b, void *p1,
		void *p2)
{
	free_all(stack_a);
	free_all(stack_b);
	free(p1);
	free(p2);
}

static void	exit_error_bonus(t_stack *stack_a, t_stack *stack_b, void *p1,
	void *p2)
{
	free_all(stack_a);
	free_all(stack_b);
	free(p1);
	free(p2);
	exit(EXIT_FAILURE);
}

static char	*one_line_operation(t_stack *stack_a, t_stack *stack_b, int *array,
	char *line)
{
	if (!is_command(line))
		exit_error_bonus(stack_a, stack_b, array, line);
	do_operation(line, stack_a, stack_b);
	free(line);
	line = get_next_line(0);
	return (line);
}

static char	**set_new_arg(int *argc, char **argv, int *flag)
{
	argv = ft_split(argv[1], ' ');
	argv = append_argv(argv);
	*argc = get_new_argc(argv);
	*flag = 1;
	return (argv);
}

int	main(int argc, char **argv)
{
	int		*array;
	char	*line;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		flag;

	flag = 0;
	if (argc == 2)
		argv = set_new_arg(&argc, argv, &flag);
	if (!validate_args(argc, argv))
		exit_error(NULL, NULL, NULL);
	array = init_array(argc, argv);
	stack_a = init_stack(argc, array);
	stack_b = head_node();
	if (!stack_b)
		exit_error(stack_a, NULL, array);
	line = get_next_line(0);
	while (line)
		line = one_line_operation(stack_a, stack_b, array, line);
	print_result(stack_a, stack_b);
	if (flag == 1)
		free_double_ptr(argv);
	free_all_memory(stack_a, stack_b, array, NULL);
	return (0);
}
