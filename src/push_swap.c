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



void	sort_under_five(t_stack *stack_a, t_stack *stack_b)
{
	size_t	size;
	int		min;

	size = get_stack_size(stack_a);
	min = get_min_from_stack(stack_a);
	if (size == 4)
	{
		if (stack_a->next->index == min)
			pb(stack_a, stack_b);
		else if (stack_a->next->next->index == min)
		{
			ra(stack_a);
			pb(stack_a, stack_b);
			sort_under_three(stack_a);
			pa(stack_a, stack_b);
		}
		else if (stack_a->next->next->next->index == min)
		{
			ra(stack_a);
			ra(stack_a);
			pb(stack_a, stack_b);
			sort_under_three(stack_a);
			pa(stack_a, stack_b);
		}
		else
		{
			rra(stack_a);
			pb(stack_a, stack_b);
			sort_under_three(stack_a);
			pa(stack_a, stack_b);
		}
	}
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	size_t	size;
	
	if (is_sorted(stack_a))
		return ;
	size = get_stack_size(stack_a);
	if (size <= 3)
		sort_under_three(stack_a);
	else if (size <= 5)
		sort_under_five(stack_a, stack_b);

}

int	main(int argc, char **argv)
{
	int		*array;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!validate_args(argc, argv))
		exit_error(NULL, NULL);
	array = init_array(argc, argv);
	if (!array)
		exit_error(NULL, NULL);
	stack_a = init_stack(argc, array);
	stack_b = head_node();
	if (!stack_b)
	{
		free_all(stack_a);
		exit_error(array, NULL);
	}
	push_swap(stack_a, stack_b);
	free(array);
	return (0);
}
