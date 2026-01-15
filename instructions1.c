#include "push_swap.h"

void sa(t_stack **stack, int n)
{
    t_stack *first;
    t_stack *second;

    if(stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return ; 
    first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
    if(n == 1)
        write(1,"sa\n",3);
}

void sb(t_stack **stack, int n)
{
    t_stack *first;
    t_stack *second;

    if(stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return ; 
    first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
    if(n == 1)
        write(1,"sb\n",3);
}

void ss(t_stack **a, t_stack **b)
{
    sa(a, 0);
    sb(b, 0);
    write(1,"ss\n",3);
}