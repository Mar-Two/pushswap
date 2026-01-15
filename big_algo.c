#include "push_swap.h"

void condition_move_stack_a(t_stack **a, int chunk, int j, int first)
{
    int last;

    last = get_last_pos(*a, j, j + chunk);
    if(first <= (length_stack(*a) - last))
    {
        while(*a != NULL && !((*a)->index >= j && (*a)->index <= j + chunk))
            ra(a, 1);
    }
    else
    {
        while(*a != NULL &&!((*a)->index >= j && (*a)->index <= j + chunk))
            rra(a, 1);
    }
}

void move_and_push_b(t_stack **a,t_stack **b, int chunk, int max_limit)
{
    int j;
    int first;

    j = 0;
    while(length_stack(*a) > 3)
    {
        first = get_first_pos(*a, j, j + chunk);
        if (first == -1)
        {
            j += chunk;
            continue;
        }
        condition_move_stack_a(a, chunk, j, first);
        if ((*a)->index < max_limit)
        {
            pb(a, b);
            if((*b)->index < (j + chunk / 2))
                rb(b, 1);
        }
        else
            ra(a, 1);
    }
}

void condition_move_stack_b(t_stack **b, t_stack **a, int i, int pos)
{
    int size_b;

    size_b = length_stack(*b);
    if(pos <= size_b / 2)
    {
        while((*b)->index != i)
        {
            if ((*b)->index == i - 1)
                pa(b, a);
            else
                rb(b, 1);
        }
    }
    else 
    {
        while((*b)->index != i)
        {
            if ((*b)->index == i - 1)
                pa(b, a);
            else
                rrb(b, 1);
        }
    }
}

void move_and_push_a(t_stack **a,t_stack **b)
{
    int i;
    int pos;

    i = length_stack(*a) + length_stack(*b) - 1;
    while(*b != NULL)
    {
        pos = pos_index(*b, i);
        if (pos == -1)
        {
            i--;
            continue;
        }
        condition_move_stack_b(b, a, i, pos);
        pa(b, a);
        if (length_stack(*a) > 1 && (*a)->index > (*a)->next->index)
        {
            sa(a, 1);
            i--; 
        }
        i--;
    }
}

void algo_trie_grande_liste(t_stack **a,t_stack **b, int len)
{
    int chunk;
    int max_limit;

    if (is_sorted(*a))
        return ;
    if( len <= 50)
        chunk = 9;
    if (len <= 200)
        chunk = 18;
    if (len > 200 && len <= 350)
        chunk = 36;
    if (len > 350)
        chunk = 54;
    max_limit = len - 3;
    move_and_push_b(a, b, chunk, max_limit);
    algo_trie_3(a);
    move_and_push_a(a, b);
}
