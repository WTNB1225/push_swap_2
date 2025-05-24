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

int	get_max_from_stack(t_stack *stack)
{
	int		max;
	t_stack *current;

	max = 0;
	current = stack->next;
	while (current != stack)
	{
		if (max < current->index)
			max = current->index;
		current = current->next;
	}
	return (max);
}

int	get_min_from_stack(t_stack *stack)
{
	int		min;
	t_stack *current;

	min = 0;
	current = stack->next;
	while (current != stack)
	{
		if (min > current->index)
			min = current->index;
		current = current->next;
	}
	return (min);
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
