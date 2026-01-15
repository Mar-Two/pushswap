#include "push_swap.h"

void ra(t_stack **stack,int n)
{
    t_stack *first;
    t_stack *last;

    if(stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return ;
    first = *stack;
    last = *stack;
    while(last->next != NULL)
        last = last->next;
    *stack = first->next;
    last->next = first;
    first->next = NULL;
    if(n == 1)
        write(1,"ra\n",3);
}

void rb(t_stack **stack,int n)
{
    t_stack *first;
    t_stack *last;

    if(stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return ;
    first = *stack;
    last = *stack;
    while(last->next != NULL)
        last = last->next;
    *stack = first->next;
    last->next = first;
    first->next = NULL;
    if(n == 1)
        write(1,"rb\n",3);
}

void rr(t_stack **a, t_stack **b)
{
    ra(a, 0);
    rb(b, 0);
    write(1,"rr\n",3);
}

