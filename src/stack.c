/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 07:10:25 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/01 02:22:00 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*head_node(void)
{
	t_stack	*head;

	head = (t_stack *)malloc(sizeof(t_stack));
	if (!head)
		return (NULL);
	head->next = head;
	head->prev = head;
	head->value = INT_MIN;
	return (head);
}

void	add_tail(t_stack *head, t_stack *node)
{
	t_stack	*tmp;

	if (!node)
		return ;
	tmp = head;
	while (tmp->next != head)
		tmp = tmp->next;
	node->prev = tmp;
	node->next = head;
	tmp->next = node;
	head->prev = node;
}

void	free_all(t_stack *head)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!head)
		return ;
	tmp = head->next;
	while (tmp != head)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
	free(head);
}

t_stack	*pop(t_stack *stack)
{
	t_stack	*move;

	if (stack->next == stack)
		return (NULL);
	move = stack->next;
	stack->next = move->next;
	move->next->prev = stack;
	move->next = NULL;
	move->prev = NULL;
	return (move);
}

void	push(t_stack *stack, t_stack *node)
{
	if (node == NULL)
		return ;
	node->next = stack->next;
	stack->next->prev = node;
	node->prev = stack;
	stack->next = node;
}
