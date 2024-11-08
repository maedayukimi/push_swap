/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <maedayukimi@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:06:33 by mawako            #+#    #+#             */
/*   Updated: 2024/11/08 20:54:30 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	char	input[100];

	while (1)
	{
		printf("push, swap, rotate, or re rotate?: ");
		if (fgets(input, sizeof(input), stdin) != NULL)
		{
			if (input[0] == 'q')
				break;
			else if (strcmp(input, "pa\n") == 0)
				push(a, b);
			else if (strcmp(input, "pb\n") == 0)
				push(b, a);
			else if (strcmp(input, "sa\n") == 0)
				swap(a);
			else if (strcmp(input, "sb\n") == 0)
				swap(b);
			else if (strcmp(input, "ra\n") == 0)
				rotate(a);
			else if (strcmp(input, "rb\n") == 0)
				rotate(b);
			else if (strcmp(input, "rra\n") == 0)
				reverse_rotate(a);
			else if (strcmp(input, "rrb\n") == 0)
				reverse_rotate(b);
		}
	}	
}
