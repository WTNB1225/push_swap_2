/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 02:24:22 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/01 02:27:40 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_array(int *array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		printf("%d ", array[i]);
		i++;
	}
}

int	*init_array(int argc, char **argv)
{
	size_t	i;
	int		*array;

	array = (int *)malloc(sizeof(int) * argc - 1);
	if (!array)
		exit_error(NULL, NULL, NULL);
	i = 0;
	argv++;
	while (argv[i])
	{
		array[i] = ft_atoi(argv[i]);
		i++;
	}
	coord_compression(array, argc - 1);
	return (array);
}

t_stack	*init_stack(int argc, int *array)
{
	size_t	i;
	t_stack	*head;
	t_stack	*node;

	i = 0;
	head = head_node();
	if (!head)
		exit_error(NULL, NULL, array);
	while (i < (size_t)argc - 1)
	{
		node = (t_stack *)malloc(sizeof(t_stack));
		if (!node)
			exit_error(head, NULL, array);
		node->value = array[i];
		add_tail(head, node);
		i++;
	}
	return (head);
}
