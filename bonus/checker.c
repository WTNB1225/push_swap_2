/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:27:48 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/01 17:52:00 by wyuki            ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int		*array;
	char	*line;
	t_stack	*stack_a;
	t_stack	*stack_b;

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
	if (is_sorted(stack_a) && get_stack_size(stack_b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_all_memory(stack_a, stack_b, array, NULL);
	return (0);
}
