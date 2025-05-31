/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 01:11:02 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/01 02:25:36 by wyuki            ###   ########.fr       */
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

static void	pb_max_value(t_stack *stack_a, size_t max_idx)
{
	size_t	i;

	i = 0;
	if (max_idx <= 2)
	{
		while (i++ < max_idx)
			ra(stack_a);
	}
	else
		rra(stack_a);
}

static void	pb_and_all_pa(t_stack *stack_a, t_stack *stack_b)
{
	pb(stack_a, stack_b);
	sort_under_three(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
	pa(stack_a, stack_b);
}

static void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	size_t	min_idx;
	size_t	max_idx;
	size_t	i;

	min_idx = get_index(stack_a, 0);
	i = 0;
	if (min_idx <= 2)
	{
		while (i++ < min_idx)
			ra(stack_a);
	}
	else
	{
		while (min_idx++ <= 4)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	max_idx = get_index(stack_a, 4);
	pb_max_value(stack_a, max_idx);
	pb_and_all_pa(stack_a, stack_b);
}

void	sort_under_five(t_stack *stack_a, t_stack *stack_b)
{
	size_t	size;

	size = get_stack_size(stack_a);
	if (size == 4)
		sort_four(stack_a, stack_b);
	else
		sort_five(stack_a, stack_b);
}
