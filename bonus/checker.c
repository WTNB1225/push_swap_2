/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:27:48 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/27 19:27:48 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int main(int argc, char *argv)
{
    int     *array;
    char    *line;
    t_stack *stack_a;
    t_stack *stack_b;

    if (!validate_args(argc, argv))
        exit_error(NULL, NULL);
    array = init_array(argc, argv);
    if (!array)
        exit_error(NULL, NULL);
    stack_a = init_stack(argc, argv);
    stack_b = head_node();
    if (!stack_b)
    {
        free_all(stack_a);
        exit_error(array, NULL);
    }
    while ((line = get_next_line(0)) != NULL)
    {
        if (!is_command(line))
        {
            free_all(stack_a);
            free_all(stack_b);
            exit_error(array, NULL);
        }
        do_operation()
    }
    
}

// int	main(int argc, char **argv)
// {
// 	int		*array;
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;

// 	if (!validate_args(argc, argv))
// 		exit_error(NULL, NULL);
// 	array = init_array(argc, argv);
// 	if (!array)
// 		exit_error(NULL, NULL);
// 	stack_a = init_stack(argc, array);
// 	stack_b = head_node();
// 	if (!stack_b)
// 	{
// 		free_all(stack_a);
// 		exit_error(array, NULL);
// 	}
// 	push_swap(stack_a, stack_b);
// 	free(array);
// 	// print_stack(stack_a);
// 	return (0);
// }
