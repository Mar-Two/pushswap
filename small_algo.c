#include "push_swap.h"
void algo_trie_2(t_stack **a)
{
	long first;
	long second;

	if ((*a)->next == NULL)
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	if (first > second)
		sa(a, 1);
}

void algo_trie_3(t_stack **a)
{
	long first;
	long second;
	long three;

	first = (*a)->value;
	second = (*a)->next->value;
	three = (*a)->next->next->value;
	if (is_sorted(*a))
		return ;
	if (first > second && first < three)
		sa(a, 1);
	if (first > second && first > three && second < three)
		ra(a, 1);
	if (first > second && first > three && second > three)
	{
		ra(a, 1);
		sa(a, 1);
	}
	if (first < second && first > three)
		rra(a, 1);
	if (first < second && first < three && second > three)
	{
		rra(a, 1);
		sa(a , 1);
	}
}

void move_stack_a_small(t_stack **a, int current_len, int j)
{
	if (pos_index(*a, j) > current_len / 2)
	{
		while((*a)->index != j)
			rra(a, 1);
	}
	else
	{
		while((*a)->index != j)
			ra(a, 1);
	}
}

void algo_trie_petite_liste(t_stack **a, t_stack **b, int len)
{
	int i;
	int j;
	int current_len;

	i = 0;
	j = 0;
	if (is_sorted(*a))
		return ;
	while(i < len - 3)
	{
		current_len = length_stack(*a);
		move_stack_a_small(a, current_len, j);
		pb(a, b);
		j++;
		i++;
	}
	algo_trie_3(a);
	while (*b != NULL)
		pa(b, a);
}