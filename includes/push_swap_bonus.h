/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:10:55 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/01 22:23:18 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"

int		is_command(const char *line);
void	do_operation(char *line, t_stack *stack_a, t_stack *stack_b);
void	print_result(t_stack *stack_a, t_stack *stack_b);
#endif
