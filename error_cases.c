/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <maedayukimi@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:33:28 by mawako            #+#    #+#             */
/*   Updated: 2024/11/07 13:29:25 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate(int *nums, int size)
{
	int	index1;
	int	index2;

	index1 = 0;
	while (index1 < size)
	{
		index2 = index1 + 1;
		while (index2 < size)
		{
			if (nums[index1] == nums[index2])
			{
				ft_printf("Error: Duplicated number");
				free(nums);
				exit(1);
			}
			index2++;
		}
		index1++;
	}
}

void	check_number(char *av, int *array)
{
	check_integer(av, array);
	if (*av == '-' || *av == '+')
		av++;
	while (*av)
	{
		if (!(*av >= '0' && *av <= '9'))
		{
			ft_printf("Error: Not number");
			free(array);
			exit(1);
		}
		av++;
	}
}

void	check_integer(char *av, int *array)
{
	if (ft_atol(av) > 2147483647 || ft_atol(av) < -2147483648)
	{
		ft_printf("Error: Not integer number");
		free(array);
		exit(1);
	}
}
