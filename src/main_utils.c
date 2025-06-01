/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 21:08:09 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/01 21:09:00 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**append_argv(char **argv)
{
	size_t	i;
	size_t	len;
	char	**new_argv;

	i = 0;
	while (argv[i])
		i++;
	new_argv = (char **)malloc(sizeof(char *) * (i + 2));
	if (!new_argv)
	{
		free_double_ptr(argv);
		exit_error(NULL, NULL, NULL);
	}
	len = i + 1;
	i = 1;
	new_argv[0] = ft_strdup("./push_swap");
	while (i < len)
	{
		new_argv[i] = ft_strdup(argv[i - 1]);
		i++;
	}
	new_argv[i] = NULL;
	free_double_ptr(argv);
	return (new_argv);
}

int	get_new_argc(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}
