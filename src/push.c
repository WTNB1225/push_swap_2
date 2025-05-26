/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 02:08:45 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/26 01:08:59 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*move;

	if (stack_b->next == stack_b)
		return ;
	move = pop(stack_b);
	push(stack_a, move);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*move;

	if (stack_a->next == stack_a)
		return ;
	move = pop(stack_a);
	push(stack_b, move);
	ft_putstr_fd("pb\n", 1);
}
