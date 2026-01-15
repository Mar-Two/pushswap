#include "push_swap.h"

void pb(t_stack **a,t_stack **b)
{
    t_stack *head_a;
    t_stack *head_b;
    t_stack *tmp;

    if(a == NULL || *a == NULL)
        return ;
    head_a = *a;
    tmp = head_a->next;
    head_b = *b;
    head_a->next = head_b;
    *a = tmp;
    *b = head_a;
    write(1,"pb\n",3);
}

void pa(t_stack **b,t_stack **a)
{
    t_stack *head_b;
    t_stack *head_a;
    t_stack *tmp;

    if(b == NULL || *b == NULL)
        return ;
    head_b = *b;
    tmp = head_b->next;
    head_a = *a;
    head_b->next = head_a;
    *b = tmp;
    *a = head_b;
    write(1,"pa\n",3);
}