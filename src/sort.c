/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 05:01:21 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/26 03:48:56 by wyuki            ###   ########.fr       */
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

int	check_opposite(t_stack *stack)
{
	size_t	size;
	size_t	count;
	t_stack *current;
	int	diff;

	diff = 0;
	count = 0;
	size = get_stack_size(stack);
	current = stack->next;
	while (current->next != stack)
	{
		diff = current->value - current->next->value;
		if (diff == 2 || diff == 3 || diff == 4)
			count++;
		current = current->next;
	}
	if (count * 10 >= size * 6)
		return (1);
	return (0);
}

void	pb_or_ra(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	range;
	size_t	size;
	int		stack_idx;

	range = 13;
	i = 0;
	while ((size = get_stack_size(stack_a)) > 0)
	{
		stack_idx = stack_a->next->value;
		if (stack_idx <= i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if (stack_idx <= i + range)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if (check_opposite(stack_a))
			rra(stack_a);
		else
			ra(stack_a);
	}
}

void	pa_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max;
	size_t	max_idx;
	size_t	size;
	size_t	i;
	i = 0;
	while ((size = get_stack_size(stack_b)) > 0)
	{
		i = 0;
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
			if (max_idx <= size / 2)
			{
				while (i < max_idx)
				{
					rb(stack_b);
					i++;
				}
			}
			else
			{
				max_idx = get_index(stack_b, max);
				while (max_idx <= size)
				{
					rrb(stack_b);
					max_idx++;
				}
			}
		}
	}
}

void	sort_over_six(t_stack *stack_a, t_stack *stack_b)
{
	pb_or_ra(stack_a, stack_b);
	pa_sort(stack_a, stack_b);
}

