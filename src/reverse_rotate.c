/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 06:16:10 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/26 03:39:55 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_rotate(t_stack *stack)
{
	t_stack	*move;

	move = stack->prev;
	if (move == stack)
		return ;
	move->prev->next = stack;
	stack->prev = move->prev;
	push(stack, move);
}

void	rra(t_stack *stack_a)
{
	r_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *stack_b)
{
	r_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
