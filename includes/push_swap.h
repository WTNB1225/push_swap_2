/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 00:21:13 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/26 02:57:04 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	struct s_stack *prev;
	struct s_stack *next;
	int				value;
}   t_stack;

void	exit_error(void *ptr, void *ptr2);
int		validate_args(int argc, char **argv);

void	print_array(int *array, size_t size);
int		*init_array(int argc, char **argv);
void	coord_compression(int *array, size_t size);

t_stack	*head_node(void);
void	add_tail(t_stack *head, t_stack *node);
void	free_all(t_stack *head);
t_stack	*init_stack(int argc, int *array);

size_t	get_stack_size(t_stack *t_stack);
int		get_max_from_stack(t_stack *stack);
int		get_min_from_stack(t_stack *stack);
size_t	get_index(t_stack *t_stack, int value);

size_t	is_sorted(t_stack *stack);
void	sort_under_three(t_stack *stack_a);
void	sort_under_five(t_stack *stack_a, t_stack *stack_b);

void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
#endif
