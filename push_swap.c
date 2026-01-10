#include "push_swap.h"
#include <stdio.h>

/*
typedef struct s_stack_a
{
    long value;
    int index;
    struct s_stack_a *next;
} t_stack;

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

void exit_error(char **s_split,t_stack **pile_a)
{
    t_stack *tmp;

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
}*/

void afficherListe(t_stack *maListe)
{
    while(maListe)
    {
        printf("%ld\n",maListe->value);
        maListe = maListe->next;
    }
}

int main(int argc, char *argv[])
{
    int i;
    char **s_split;
    t_stack *a;
    t_stack *b;
    int len;

    b = NULL;
    a = NULL;
    s_split = NULL;
    if(argc < 2)
        return (1);
    i = 1;
    while (i < argc)
    {
        s_split = ft_split(argv[i],' ');
        s_split_empty(s_split,&a);
        value_atoi(s_split,&a);
        free_split(s_split);
        s_split = NULL;
        i++;
    }
    len = length_stack(a);
    //printf("%d",is_sorted(a));
    afficherListe(a);
    all_algo(&a, &b, len);
    printf("Pile trier\n");
    printf("<-------->\n");
    afficherListe(a);
    printf("Pile B\n");
    printf("<-------->\n");
    afficherListe(b);
    /*
    printf("PILE A\n");
    afficherListe(a);
    pb(&a,&b);
    printf("PILE A\n");
    afficherListe(a);
    printf("PILE B\n");
    afficherListe(b);
    pb(&a,&b);
    printf("PILE A\n");
    afficherListe(a);
    printf("PILE B\n");
    afficherListe(b);
    pa(&b,&a);
    printf("PILE A\n");
    afficherListe(a);
    printf("PILE B\n");
    afficherListe(b);
    pa(&b,&a);
    printf("PILE A\n");
    afficherListe(a);
    printf("PILE B\n");
    afficherListe(b);*/
    //rra(&a,1);
    //afficherListe(b);
    /*
    sa(&a,1);
    afficherListe(a);
    ra(&a,1);
    afficherListe(a);*/
    return (0);
}