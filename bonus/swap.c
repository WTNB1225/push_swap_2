/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 02:10:17 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/29 02:52:32 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	swap(t_stack *stack)
{
	size_t	stack_size;
	int		tmp;

	stack_size = get_stack_size(stack);
	if (stack_size <= 1)
		return ;
	tmp = stack->next->value;
	stack->next->value = stack->next->next->value;
	stack->next->next->value = tmp;
}

void	sa(t_stack *stack_a)
{
	swap(stack_a);
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
