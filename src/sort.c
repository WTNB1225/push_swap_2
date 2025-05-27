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

void	pb_or_ra(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	range;
	size_t	size;
	int		stack_idx;

	if (get_stack_size(stack_a) <= 100)
		range = 13;
	else
		range = 32;
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
				rb(stack_b);
			}
			else
			{
				rrb(stack_b);
			}
		}
	}
}

// void	big_sort(t_stack *stack_a, t_stack *stack_b, int range)
// // {
// 	int	i;

// 	i = 0;
// 	while (get_stack_size(stack_a) > 0)
// 	{
// 		if ((stack_a)->next->value <= i)
// 		{
// 			pb(stack_a, stack_b);
// 			++i;
// 		}
// 		else if ((stack_a)->next->value <= i + range)
// 		{
// 			pb(stack_a, stack_b);
// 			rb(stack_b);
// 			++i;
// 		}
// 		else if (check_opposite(stack_a))
// 			rra(stack_a);
// 		else
// 			ra(stack_a);
// 	}
// }

// void	final_sort(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	idx;
// 	int max;
// 	max = get_max_from_stack(stack_b);
// 	while (get_stack_size(stack_b) > 0)
// 	{
// 		max = get_max_from_stack(stack_b);
// 		if ((stack_b)->next->value== max)
// 		{
// 			pa(stack_a, stack_b);
// 		}
// 		else if ((stack_b)->next->next->value == max)
// 		{
// 			sb(stack_b);
// 			pa(stack_a, stack_b);
// 		}
// 		else
// 		{
// 			idx = get_index(stack_b, max);
// 			if (!best_move(stack_b, idx))
// 				rrb(stack_b);
// 			else
// 				rb(stack_b);
// 		}
// 	}
// }

void	sort_over_six(t_stack *stack_a, t_stack *stack_b)
{
	pb_or_ra(stack_a, stack_b);
	pa_sort(stack_a, stack_b);
}

