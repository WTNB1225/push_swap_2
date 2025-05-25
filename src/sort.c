/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 05:01:21 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/26 01:56:28 by wyuki            ###   ########.fr       */
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
	if (a < b && c < b)
	{
		rra(stack);
		sa(stack);
	}
	else if (b < a && a < c)
		sa(stack);
	else if (b < c && c < a)
		rra(stack);
	else if (c < a && a < b)
		ra(stack);
	else if (c < b && b < a)
	{
		ra(stack);
		sa(stack);
	}
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
