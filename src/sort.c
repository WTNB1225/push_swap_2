/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 05:01:21 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/26 03:32:44 by wyuki            ###   ########.fr       */
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
