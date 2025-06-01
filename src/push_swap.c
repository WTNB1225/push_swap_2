/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 00:17:58 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/01 21:29:33 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	size_t	size;

	if (is_sorted(stack_a))
		return ;
	size = get_stack_size(stack_a);
	if (size <= 3)
		sort_under_three(stack_a);
	else if (size <= 5)
		sort_under_five(stack_a, stack_b);
	else
		sort_over_six(stack_a, stack_b);
}

static char	**set_new_arg(int *argc, char **argv)
{
	argv = ft_split(argv[1], ' ');
	argv = append_argv(argv);
	*argc = get_new_argc(argv);
	return (argv);
}

int	main(int argc, char **argv)
{
	int		*array;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		flag;

	flag = 0;
	if (argc == 2)
	{
		argv = set_new_arg(&argc, argv);
		flag = 1;
	}
	if (!validate_args(argc, argv))
		exit_error(NULL, NULL, NULL);
	array = init_array(argc, argv);
	stack_a = init_stack(argc, array);
	stack_b = head_node();
	if (!stack_b)
		exit_error(stack_a, NULL, array);
	push_swap(stack_a, stack_b);
	free(array);
	free_all(stack_a);
	free_all(stack_b);
	if (flag == 1)
		free_double_ptr(argv);
	return (0);
}
