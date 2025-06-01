/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:18:33 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/01 18:00:22 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_command(const char *line)
{
	const char	*commands[] = {"sa", "sb", "ss", "ra", "rb", "rr",
		"rra", "rrb", "rrr", "pa", "pb"};
	size_t		command_num;
	size_t		i;

	command_num = 11;
	i = 0;
	while (i < command_num)
	{
		if (ft_strcmp(line, commands[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	do_operation(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strcmp(line, "sa"))
		sa(stack_a);
	else if (!ft_strcmp(line, "sb"))
		sb(stack_b);
	else if (!ft_strcmp(line, "ss"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(line, "ra"))
		ra(stack_a);
	else if (!ft_strcmp(line, "rb"))
		rb(stack_b);
	else if (!ft_strcmp(line, "rr"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(line, "rra"))
		rra(stack_a);
	else if (!ft_strcmp(line, "rrb"))
		rrb(stack_b);
	else if (!ft_strcmp(line, "rrr"))
		rrr(stack_a, stack_b);
	else if (!ft_strcmp(line, "pa"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(line, "pb"))
		pb(stack_a, stack_b);
}
