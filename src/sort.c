/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 05:01:21 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/29 00:05:27 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->next->value;
	b = stack->next->next->value;
	c = stack->next->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}

void	sort_under_three(t_stack *stack)
{
	size_t	size;

	size = get_stack_size(stack);
	if (size == 1)
		return ;
	if (size == 2)
		sa(stack);
	if (size == 3)
		sort_three(stack);
}

static void	all_pb(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		range;

	if (get_stack_size(stack_a) <= 100)
		range = 13;
	else
		range = 32;
	i = 0;
	while (get_stack_size(stack_a) > 0)
	{
		if (stack_a->next->value <= i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if (stack_a->next->value <= i + range)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

static void	all_pa(t_stack *stack_a, t_stack *stack_b)
{
	int		max;
	size_t	max_idx;

	while (get_stack_size(stack_b) > 0)
	{
		max = get_max_from_stack(stack_b);
		if (stack_b->next->value == max)
			pa(stack_a, stack_b);
		else if (stack_b->next->next->value == max)
		{
			sb(stack_b);
			pa(stack_a, stack_b);
		}
		else
		{
			max_idx = get_index(stack_b, max);
			if (max_idx <= get_stack_size(stack_b) / 2)
				rb(stack_b);
			else
				rrb(stack_b);
		}
	}
}

void	sort_over_six(t_stack *stack_a, t_stack *stack_b)
{
	all_pb(stack_a, stack_b);
	all_pa(stack_a, stack_b);
}
