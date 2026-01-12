#include "push_swap.h"
#include <stdio.h>
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
            if(index_node->value > all_stack->value)
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
void algo_trie_2(t_stack **a)
{
    long first;
    long second;

    if((*a)->next == NULL)
        return ;
    first = (*a)->value;
    second = (*a)->next->value;
    if(first > second)
    {
        sa(a, 1);
    }
}

void algo_trie_3(t_stack **a)
{
    long first;
    long second;
    long three;

    first = (*a)->value;
    second = (*a)->next->value;
    three = (*a)->next->next->value;
    if(is_sorted(*a))
        return ;
    if(first > second && first < three)
        sa(a, 1);
    if(first > second && first > three && second < three)
        ra(a, 1);
    if(first > second && first > three && second > three)
    {
        ra(a, 1);
        sa(a, 1);
    }
    if(first < second && first > three)
        rra(a, 1);
    if(first < second && first < three && second > three)
    {
        rra(a, 1);
        sa(a , 1);
    }
}

void algo_trie_4(t_stack **a,t_stack **b)
{
    if(is_sorted(*a))
        return ;
    while((*a)->index != 0)
        ra(a, 1);
    pb(a, b);
    algo_trie_3(a);
    pa(b, a);
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
/*
void algo_trie_all(t_stack **a,t_stack **b, int len)
{
    int i;
    int j;
    int count_b;

    i = 0;
    j = 0;
    count_b = 0;
    if(is_sorted(*a))
        return ;
    int all_len = len;
    while(i < all_len - 3)
    {
        len = length_stack(*a);
        if(pos_index(*a, j) > len / 2)
        {
            while((*a)->index >= j && (*a)->index <= j + 15)
            {
                rra(a, 1);
            }
        }
        else
        {
            while((*a)->index != j)
            {
                ra(a, 1);
            }
        }
        pb(a, b);
        count_b++;
        if(count_b == 15)
        {
            algo_trie_15(b,a , len);
            count_b = 0;
        }
        j++;
        i++;
    }
    algo_trie_3(a);
    while(i > 0)
    {
        pa(b, a);
        i--;
    }
}*/
/*
void algo_trie_15(t_stack **a,t_stack **b, int len)
{
    int i;
    int j;
    int count_b;
    
    i = 0;
    j = 0;
    count_b = 0;
    if(is_sorted(*b))
        return ;
    int all_len = len;
    while(i < all_len - 3)
    {
        len = length_stack(*a);
        if(pos_index(*a, j) > len / 2)
        {
            while((*a)->index != j)
            {
                rra(a, 1);
            }
        }
        else
        {
            while((*a)->index != j)
            {
                ra(a, 1);
            }
        }
        pb(a, b);
        count_b++;
        if(count_b == 3)
        {
            algo_trie_3(a);
            count_b = 0;
        }
        j++;
        i++;
    }
    algo_trie_3(a);
    while(i > 0)
    {
        pa(b, a);
        i--;
    }
}
*/
void algo_trie_grande_liste(t_stack **a,t_stack **b, int len)
{
    int i;
    int j;
    int chunk;

    i = 0;
    j = 0;
    chunk = 15;
    if(is_sorted(*a))
        return ;
    int max_limit = len - 3;
    while(length_stack(*a) > 3)
    {
        int first = get_first_pos(*a, j, j + chunk);
        int last = get_last_pos(*a, j, j + chunk);
        int size = length_stack(*a);
       
        if (first == -1)
        {
            j += 16;
            continue;
        }
        else if(first <= (size - last))
        {
            while(*a != NULL && !((*a)->index >= j && (*a)->index <= j + chunk))
            {   
                ra(a, 1);
            }
        }
        else
        {
            while(*a != NULL &&!((*a)->index >= j && (*a)->index <= j + chunk))
            {
                rra(a, 1);
            }
        }
        if ((*a)->index < max_limit)
            pb(a, b);
        else
            ra(a, 1);
    }
    i = length_stack(*a) + length_stack(*b) - 1;
    algo_trie_3(a);
    while(*b != NULL)
    {
        int current_len = length_stack(*b);
        int pos = pos_index(*b, i);
        if (pos == -1)
        {
            i--;
            continue;
        }
        if(pos <= current_len / 2)
        {
            while((*b)->index != i)
                rb(b, 1);
        }
        else 
        {
            while((*b)->index != i)
                rrb(b, 1);
        }
        pa(b, a);
        i--;
    }
}

void algo_trie_petite_liste(t_stack **a,t_stack **b, int len)
{
    int i;
    int j;
    int actual_len;

    i = 0;
    j = 0;
    if(is_sorted(*a))
        return ;
    
    while(i < len - 3)
    {
        actual_len = length_stack(*a);
        if(pos_index(*a, j) > actual_len / 2)
        {
            while((*a)->index != j)
            {
                rra(a, 1);
            }
        }
        else
        {
            while((*a)->index != j)
            {
                ra(a, 1);
            }
        }
        pb(a, b);
        j++;
        i++;
    }
    algo_trie_3(a);
    while (*b != NULL)
    {
        pa(b, a);
    }
}
/*
void algo_trie_15(t_stack **a, t_stack **b, int len)
{
    int i = 0;
    int j = 0;
    int current_len;

    if (is_sorted(*a)) // On vérifie A, pas B !
        return ;

    // 1. On pousse TOUT vers B, sauf les 3 derniers
    while (i < len - 3)
    {
        current_len = length_stack(*a);
        if (pos_index(*a, j) > current_len / 2)
        {
            while ((*a)->index != j)
                rra(a, 1);
        }
        else
        {
            while ((*a)->index != j)
                ra(a, 1);
        }
        pb(a, b);
        j++;
        i++;
    }

    // 2. Maintenant qu'il reste EXACTEMENT 3 nombres dans A, on les trie
    algo_trie_3(a);

    // 3. On ramène tout de B vers A
    while (*b != NULL)
    {
        pa(b, a);
    }
}*/
void all_algo(t_stack **a, t_stack **b, int len)
{
    if (len == 0 || len == 1)
        return ;
    if(len < 3)
        algo_trie_2(a);
    if(len == 3)
        algo_trie_3(a);
    if (len <= 10)
        algo_trie_petite_liste(a, b, len);
    if (len > 10)
        algo_trie_grande_liste(a, b, len);
}