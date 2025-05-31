/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 00:19:47 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/01 02:28:14 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(t_stack *stack_a, t_stack *stack_b, void *ptr)
{
	ft_putstr_fd("Error\n", 2);
	free_all(stack_a);
	free_all(stack_b);
	free(ptr);
	exit(EXIT_FAILURE);
}
