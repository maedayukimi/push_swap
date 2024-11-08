#include "push_swap.h"

t_stack	*sentinel(void)
{
	t_stack	*sentinel;

	sentinel = malloc(sizeof(t_stack));
	if (!sentinel)
	{
		ft_printf("malloc Error");
		return (NULL);
	}
	sentinel->value = 0;
	sentinel->index = -1;
	sentinel->prev = sentinel;
	sentinel->next = sentinel;
	return (sentinel);
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

void	append_node(t_stack *sentinel, int value)
{
	t_stack *new_node;
	t_stack	*tail;

	new_node = malloc(sizeof(t_stack));
	new_node->value = value;
	new_node->index = 0;
	tail = sentinel->prev;
	tail->next = new_node;
	new_node->prev = tail;
	new_node->next = sentinel;
	sentinel->prev = new_node;
}

void	calculate_index(t_stack *sentinel)
{
	t_stack	*current;
	t_stack	*inner;

	current = sentinel->next;
	while (current != sentinel)
	{
		inner = sentinel->next;
		while (inner != sentinel)
		{
			if (current->value > inner->value)
				current->index++;
			inner = inner->next;
		}
		current = current->next;
	}
}

int	main(int ac, char **av)
{
	if (ac <= 1)
	{
		ft_printf("Enter number");
		return 0;
	}
	int	*array;
	int	i;
	t_stack	*sent_a;
	t_stack	*sent_b;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = 0;
	sent_a = sentinel();
	sent_b = sentinel();
	array = parse_arguments(ac, av);
	populate_stack(sent_a, array, ac - 1);
	calculate_index(sent_a);
	push_swap(sent_a, sent_b);
	stack_a = sent_a->next;
	stack_b = sent_b->next;
	while (stack_a != sent_a || stack_b != sent_b)
	{
		ft_printf("%d\n", i);
		if (stack_a != sent_a)
		{
			ft_printf("value a: %d ", stack_a->value);
			ft_printf("index a: %d ", stack_a->index);
			stack_a = stack_a->next;
		}
		else
		{
			ft_printf("value a: (end) ");
			ft_printf("index a: (end) ");
		}
		if (stack_b != sent_b)
		{
			ft_printf("value b: %d ", stack_b->value);
			ft_printf("index b: %d ", stack_b->index);
			stack_b = stack_b->next;
		}
		else
		{
			ft_printf("value b: (end) ");
			ft_printf("index b: (end) ");
		}
		ft_printf("\n\n");
		i++;
	}
/*	see pointer
	stack_a = stack_a->prev;
	while (stack_a != sent_a)
	{
		ft_printf("%d\n", i);
		ft_printf("stack_a: value %d index %d\n", stack_a->value, stack_a->index);
		ft_printf("stack_b: value %d index %d\n\n", stack_b->value);
		stack_a = stack_a->prev;
		if (stack_b->next != sent_b)
			stack_b = stack_b->next;
		i++;
	}
*/
	return (0);
}
