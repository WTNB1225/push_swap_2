/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 03:12:28 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/25 03:30:46 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*head_node(void)
{
	t_stack *head;

	head = (t_stack *)malloc(sizeof(t_stack));
	if (!head)
		return (NULL);
	head->next = head;
	head->prev = head;
	head->index = 0;
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

size_t	get_stack_size(t_stack *stack)
{
	size_t	i;
	t_stack	*current;

	if (!stack)
		return (0);
	current = stack->next;
	i = 0;
	while (current != stack)
	{
		current = current->next;
		i++;
	}
	return (i);
}

// #include <assert.h>
// int main(void)
// {
// 	t_stack *stack;
// 	t_stack *node;
// 	stack = head_node();
// 	assert(stack->next == stack);
// 	assert(stack->prev == stack);
// 	assert(stack->value == 0);
// 	assert(stack->index == 0);
// 	node = malloc(sizeof(t_stack));
// 	node->value = 1;
// 	node->index = 1;
// 	add_tail(stack, node);
// 	assert(stack->next == node);
// 	assert(stack->prev == node);
// 	assert(stack->next->value == 1);
// 	assert(stack->next->index == 1);
// 	node = malloc(sizeof(t_stack));
// 	node->value = 2;
// 	node->index = 2;
// 	add_tail(stack, node);
// 	assert(stack->next->next == node);
// 	assert(stack->prev == node);
// 	assert(stack->next->next->value == 2);
// 	assert(stack->next->next->index == 2);
// }
