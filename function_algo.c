#include "push_swap.h"

void index_stack(t_stack **stack)
{
	int i;
	t_stack *all_stack;
	t_stack *index_node;

	if (!stack || !*stack)
		return ;
	index_node = *stack;
	while(index_node != NULL)
	{
		i = 0;
		all_stack = *stack;
		while(all_stack != NULL)
		{
			if (index_node->value > all_stack->value)
				i++;
			all_stack = all_stack->next;
		}
		index_node->index = i;
		index_node = index_node->next;
	}
}

int is_sorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next != NULL)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int get_last_pos(t_stack *stack, int j, int end_j)
{
	int i = 0;
	int pos = -1;
	while (stack)
	{
		if (stack->index >= j && stack->index <= end_j)
			pos = i;
		stack = stack->next;
		i++;
	}
	return (pos);
}

int pos_index(t_stack *stack, int j)
{
	int i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->index == j)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

int get_first_pos(t_stack *stack, int j, int end_j)
{
	int i;
	t_stack *first;

	first = stack;
	i = 0;
	while (first != NULL)
	{
		if(first->index >= j && first->index <= end_j)
			return (i);
		i++;
		first = first->next;
	}
	return (-1);    
}