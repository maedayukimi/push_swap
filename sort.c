/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <maedayukimi@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:26:59 by mawako            #+#    #+#             */
/*   Updated: 2024/11/08 20:52:22 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack_add, t_stack *stack_sub)
{
	t_stack	*temp;
	t_stack	*new_head;

	if (stack_sub->next == stack_sub)
		return ;
	temp = stack_sub->next;
	new_head = stack_sub->next->next;
	stack_sub->next = new_head;
	new_head->prev = stack_sub;
	temp->next = stack_add->next;
	temp->prev = stack_add;
	stack_add->next->prev = temp;
	stack_add->next = temp;
}

void	swap(t_stack *stack)
{
	t_stack	*first;
	t_stack	*second;

	first = stack->next;
	second = first->next;
	if (first->index == -1 || second->index == -1)
		return ;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	first->prev = second;
	stack->next = second;
	second->prev = stack;
}

void	rotate(t_stack *stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*tail;

	first = stack->next;
	second = first->next;
	tail = stack->prev;
	if (first->index == -1 || second->index == -1)
		return ;
	first->next = stack;
	stack->prev = first;
	tail->next = first;
	first->prev = tail;
	stack->next = second;
	second->prev = stack;
}

void	reverse_rotate(t_stack *stack)
{
	t_stack	*first;
	t_stack	*tail;
	t_stack	*new_tail;

	first = stack->next;
	tail = stack->prev;
	new_tail = tail->prev;
	if (tail->index == -1 || new_tail->index == -1)
		return ;
	first->prev = tail;
	tail->next = first;
	stack->next = tail;
	tail->prev = stack;
	new_tail->next = stack;
	stack->prev = new_tail;
}
