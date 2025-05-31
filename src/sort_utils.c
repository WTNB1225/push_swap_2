/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 02:16:32 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/01 02:27:13 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(int *array, size_t size)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i)
		{
			if (j + 1 < size && array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	search_index(int *array, int num, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == num)
			return (i);
		i++;
	}
	return (0);
}

void	coord_compression(int *array, size_t size)
{
	int		*cpy;
	size_t	i;

	i = 0;
	cpy = (int *)malloc(sizeof(int) * size);
	if (!cpy)
		exit_error(NULL, NULL, array);
	ft_memcpy(cpy, array, sizeof(int) * size);
	sort(cpy, size);
	while (i < size)
	{
		array[i] = search_index(cpy, array[i], size);
		i++;
	}
	free(cpy);
}

size_t	is_sorted(t_stack *stack)
{
	t_stack	*current;

	current = stack->next;
	while (current->next != stack)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
