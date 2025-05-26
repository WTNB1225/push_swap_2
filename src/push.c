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
	move = stack_b->next;
	stack_b->next = move->next;
	stack_b->next->prev = stack_b;
	move->next = stack_a->next;
	move->prev = stack_a;
	stack_a->next->prev = move;
	stack_a->next = move;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*move;

	if (stack_a->next == stack_a)
		return ;
	move = stack_a->next;
	stack_a->next = move->next;
	stack_a->next->prev = stack_a;
	move->next = stack_b->next;
	move->prev = stack_b;
	stack_b->next->prev = move;
	stack_b->next = move;
	ft_putstr_fd("pb\n", 1);
}
