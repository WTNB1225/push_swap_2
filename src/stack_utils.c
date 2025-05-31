/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 03:12:28 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/01 02:25:11 by wyuki            ###   ########.fr       */
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
	t_stack	*current;

	max = 0;
	current = stack->next;
	while (current != stack)
	{
		if (max < current->value)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	get_min_from_stack(t_stack *stack)
{
	int		min;
	t_stack	*current;

	min = 0;
	current = stack->next;
	while (current != stack)
	{
		if (min > current->value)
			min = current->value;
		current = current->next;
	}
	return (min);
}

size_t	get_index(t_stack *stack, int value)
{
	t_stack	*current;
	size_t	i;

	i = 0;
	current = stack->next;
	while (current != stack)
	{
		if (current->value == value)
			return (i);
		i++;
		current = current->next;
	}
	return (0);
}

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack->next;
	while (current != stack)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
}
