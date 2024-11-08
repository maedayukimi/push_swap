/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <maedayukimi@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:55:34 by mawako            #+#    #+#             */
/*   Updated: 2024/11/07 12:24:26 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		*array;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac <= 1)
		return (0);
	array = parse_arguments(ac - 1, av);
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
	{
		free(array);
		return (1);
	}
	sentinel(stack_a);
	sentinel(stack_b);
	populate_stack(stack_a, array, ac - 1);
	push_swap(stack_a, stack_b);
	free(array);
	return (0);
}

int	*parse_arguments(int ac, char **av)
{
	int	*array;

	array = ps_atoi(ac, av);
	if (!array)
		exit(1);
	return (array);
}

void	populate_stack(t_stack *stack, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		append_node(stack, array[i]);
		i++;
	}
}
