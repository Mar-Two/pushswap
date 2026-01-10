#include "push_swap.h"

void exit_error(char **s_split,t_stack **pile_a)
{
    if(s_split)
        free_split(s_split);
    if (pile_a && *pile_a)
        free_stack(pile_a);
    write(2, "Error\n", 6);
    exit(1);
}

void s_split_empty(char **s_split,t_stack **pile_a)
{
    if (!s_split || !s_split[0])
        exit_error(s_split,pile_a);
}

long is_duplicate(t_stack *pile_a, long n)
{
    while (pile_a)
    {
        if (pile_a->value == n)
            return (1);
        pile_a = pile_a->next;
    }
    return (0);
}

void value_atoi(char **s_split,t_stack **pile_a)
{
    int k;
    long val;
    k = 0;
    while (s_split[k])
    {
        if(!(is_a_digit(s_split[k])))
        {
            exit_error(s_split,pile_a);
        }
        val = ft_atoi(s_split[k]);
        if (val > 2147483647 || val < -2147483648)
        {
            exit_error(s_split,pile_a);
        }
        if (is_duplicate(*pile_a, val))
            exit_error(s_split, pile_a);
        inserer_node(pile_a,val);    
        k++;
    }
}

int length_stack(t_stack *stack)
{
    int size;

    size = 0;
    while (stack != NULL)
    {
        size++;
        stack = stack->next;
    }
    return size;
}

int count_words(char *str, char c)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] != c && (i == 0 || str[i - 1] == c))
            count++;
        i++;
    }
    return (count);
}

char **ft_split(char *str, char sep)
{
    char **result;
    int i = 0;
    int k = 0;
    int j;
    int cc;

    result = calloc(count_words(str, sep) + 1,sizeof(char *));
    if (!result)
        return (NULL);
    while (str[k])
    {
        while (str[k] && str[k] == sep)
            k++;
        if (str[k])
        {
            cc = 0;
            while (str[k + cc] && str[k + cc] != sep)
                cc++;
            result[i] = malloc(cc + 1);
            if (!result[i])
            {
                free_split(result);
                return (NULL);
            }
            j = 0;
            while (j < cc)
                result[i][j++] = str[k++];
            result[i++][j] = '\0';
        }
    }
    result[i] = NULL;
    return (result);
}

