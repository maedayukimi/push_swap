/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <maedayukimi@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:08:33 by mawako            #+#    #+#             */
/*   Updated: 2024/11/07 13:31:05 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ps_atoi(int ac, char **av)
{
	int	*array;
	int	index;

	array = malloc(sizeof(int) * ac);
	if (!array)
		return (NULL);
	index = 0;
	av++;
	while (*av)
	{
		check_number(*av, array);
		array[index] = ft_atoi(*av);
		index++;
		av++;
	}
	check_duplicate(array, ac - 1);
	return (array);
}

long	ft_atol(const char *n)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while ((*n >= 9 && *n <= 13) || *n == 32)
		n++;
	if (*n == '+' || *n == '-')
	{
		if (*n == '-')
			sign *= -1;
		n++;
	}
	while (*n >= '0' && *n <= '9')
	{
		res = res * 10 + sign * (*n - 48);
		n++;
	}
	return (res);
}
