/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 00:17:58 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/01 02:26:53 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *stack_a, t_stack *stack_b)
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

int	main(int argc, char **argv)
{
	int		*array;
	t_stack	*stack_a;
	t_stack	*stack_b;

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
	return (0);
}
