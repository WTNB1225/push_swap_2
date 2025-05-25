/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 02:10:17 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/26 03:01:38 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}
