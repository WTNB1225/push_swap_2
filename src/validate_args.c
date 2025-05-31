/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 00:27:16 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/01 02:25:07 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_digit_str(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static long long int	ft_atolli(const char *str)
{
	size_t			i;
	long long int	sum;
	int				sign;

	i = 0;
	sign = 1;
	sum = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			sum = sum * 10 + (str[i] - '0');
		else
			break ;
		i++;
	}
	if (sign * sum > INT_MAX || sign * sum < INT_MIN)
		return (__LONG_LONG_MAX__);
	return (sum * sign);
}

static int	validate_digit(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_is_digit_str(argv[i]))
			return (0);
		if (ft_atolli(argv[i]) == __LONG_LONG_MAX__)
			return (0);
		i++;
	}
	return (1);
}

static int	validate_duplicate(char **argv)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (!ft_strcmp(argv[i], argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_args(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	argv++;
	if (!validate_digit(argv) || !validate_duplicate(argv))
		return (0);
	return (1);
}
