#include "push_swap.h"

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
    t_stack *second;
    t_stack *three;
    t_stack *four;
    second = (*a)->next;
    three = (*a)->next->next;
    four = (*a)->next->next->next;
    if(is_sorted(*a))
        return ;
    while((*a)->value > second->value || (*a)->value > three->value || (*a)->value > four->value)
        ra(a, 1);
    pb(a, b);
    algo_trie_3(a);
    pa(b, a);
}

void algo_trie_5(t_stack **a,t_stack **b)
{
    t_stack *second;
    t_stack *three;
    t_stack *four;
    t_stack *five;

    second = (*a)->next;
    three = (*a)->next->next;
    four = (*a)->next->next->next;
    five = (*a)->next->next->next->next;
    if(is_sorted(*a))
        return ;
    while((*a)->value > second->value || (*a)->value > three->value || (*a)->value > four->value || (*a)->value > five->value)
        ra(a, 1);
    pb(a, b);
    algo_trie_4(a,b);
    pa(b, a);
}
void all_algo(t_stack **a, t_stack **b, int len)
{
    if (len == 0 || len == 1)
        return ;
    if(len < 3)
        algo_trie_2(a);
    if(len == 3)
        algo_trie_3(a);
    if (len == 4)
        algo_trie_4(a, b);
    if (len == 5)
        algo_trie_5(a, b);
}