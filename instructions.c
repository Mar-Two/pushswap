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