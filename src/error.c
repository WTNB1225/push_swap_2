/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 00:19:47 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/25 00:20:57 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void *ptr, void *ptr2)
{
	ft_putstr_fd("Error\n", 2);
	free(ptr);
	free(ptr2);
	exit(EXIT_FAILURE);
}