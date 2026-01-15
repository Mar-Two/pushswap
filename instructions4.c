#include "push_swap.h"

void rra(t_stack **stack, int n)
{
    t_stack *last;
    t_stack *before;
    t_stack *first;

    if(stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return ;
    
    last = *stack;
    before = NULL;
    first = *stack;
    while (last->next != NULL)
    {
        before = last;
        last = last->next;
    }
    last->next = first;
    before->next = NULL;
    *stack = last;
    if(n == 1)
        write(1,"rra\n",4);
}

void rrb(t_stack **stack, int n)
{
    t_stack *last;
    t_stack *before;
    t_stack *first;

    if(stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return ;
    
    last = *stack;
    before = NULL;
    first = *stack;
    while (last->next != NULL)
    {
        before = last;
        last = last->next;
    }
    last->next = first;
    before->next = NULL;
    *stack = last;
    if(n == 1)
        write(1,"rrb\n",4);
}

void rrr(t_stack **a, t_stack **b)
{
    rra(a, 0);
    rrb(b, 0);
    write(1,"rrr\n",4);
}