/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 00:17:58 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/25 00:19:37 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *stack_a)
{
	size_t	size;
	
	if (is_sorted(stack_a))
		return ;
	size = get_stack_size(stack_a);
	if (size <= 3)
		sort_under_three(stack_a);
}

int	main(int argc, char **argv)
{
	int		*array;
	t_stack	*stack_a;
	//t_stack	*stack_b;

	if (!validate_args(argc, argv))
		exit_error(NULL, NULL);
	array = init_array(argc, argv);
	if (!array)
		exit_error(NULL, NULL);
	stack_a = init_stack(argc, array);
	push_swap(stack_a);
	free(array);
	return (0);
}
