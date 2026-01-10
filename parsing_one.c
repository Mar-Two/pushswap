#include "push_swap.h"

int is_a_digit(char *s)
{
    int i;

    i = 0;
    if(s[i] == 45 || s[i] == 43)
        i++;
    if(s[i] == '\0')
        return (0);
    while (s[i])
    {
        if(!(s[i] >= '0' && s[i] <= '9'))
            return (0);
        i++;
    }
    if (i > 12) 
        return (0);
    return (1);
}

void inserer_node(t_stack **pile_a, long value)
{
    t_stack *newnode;
    t_stack *last;

    newnode = malloc(sizeof(t_stack));
    if (!newnode)
        return; 
    newnode->value = value;
    newnode->next = NULL;
    if (*pile_a == NULL)
    {
        *pile_a = newnode;
        return;
    }
    last = *pile_a;
    while (last->next != NULL)
        last = last->next;
    last->next = newnode;
}

void free_split(char **s_split)
{
    int i;

    if (!s_split)
        return;
    i = 0;
    while (s_split[i]) 
    {
        free(s_split[i]);
        i++;
    }
    free(s_split);
}

void free_stack(t_stack **stack)
{
    t_stack *tmp;

    if (!stack || !*stack)
        return;
    while (*stack)
    {
        tmp = (*stack)->next; 
        free(*stack);        
        *stack = tmp;        
    }
    *stack = NULL;
}

long ft_atoi(char *str)
{
    long res;
    int sign;
    int i;

    res = 0;
    i = 0;
    sign = 1;
    if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return res * sign;
}
