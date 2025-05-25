/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 01:11:02 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/26 02:10:01 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	size_t	min_idx;
	size_t	i;

	i = 0;
	min_idx = get_index(stack_a, 0);
	if (min_idx <= 2)
	{
		while (i < min_idx)
		{
			ra(stack_a);
			i++;
		}
	}
	else
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_under_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_under_five(t_stack *stack_a, t_stack *stack_b)
{
	size_t	size;

	size = get_stack_size(stack_a);
	if (size == 4)
		sort_four(stack_a, stack_b);
}
