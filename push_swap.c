
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack_a
{
    long value;
    int index;
    struct s_stack_a *next;
} t_stack_a;

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

void inserer_node(t_stack_a **pile_a, long value)
{
    t_stack_a *newnode;
    t_stack_a *last;

    newnode = malloc(sizeof(t_stack_a));
    if (!newnode)
        return; 
    newnode->value = (int)value;
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
void free_stack(t_stack_a **stack)
{
    t_stack_a *tmp;

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

void exit_error(char **s_split,t_stack_a **pile_a)
{
    if(s_split)
        free_split(s_split);
    t_stack_a *tmp;
    if (pile_a && *pile_a)
        free_stack(pile_a);
    write(2, "Error\n", 6);
    exit(1);
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

long is_duplicate(t_stack_a *pile_a, long n)
{
    while (pile_a)
    {
        if (pile_a->value == n)
            return (1);
        pile_a = pile_a->next;
    }
    return (0);
}

void value_atoi(char **s_split,t_stack_a **pile_a)
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
/*
void check_double(char **s_split,t_stack_a *pile_a)
{
    t_stack_a *tmp;
    t_stack_a *actual;
    int count;

    actual = pile_a;
    while (actual)
    {
        tmp = pile_a;
        count = 0;
        while(tmp)
        {
            if(actual->value == tmp->value)
                count++;
            tmp = tmp->next;
        }
        if(count > 1)
            exit_error(s_split,&pile_a);
        actual = actual->next;
    }
}*/

void afficherListe(t_stack_a *maListe)
{
    while(maListe)
    {
        printf("[%ld]->",maListe->value);
        maListe = maListe->next;
    }
}

int main(int argc, char *argv[])
{
    int i;
    char **s_split;
    t_stack_a *pile_a;

    pile_a = NULL;
    s_split = NULL;
    if(argc < 2)
        return (1);
    i = 1;
    while (i < argc)
    {
        s_split = ft_split(argv[i],' ');
        if (!s_split || !s_split[0])
        {
            exit_error(s_split,&pile_a);
        }
        value_atoi(s_split,&pile_a);
        free_split(s_split);
        s_split = NULL;
        i++;
    }
    afficherListe(pile_a);
    return 0;
}

/*
int main(int argc, char *argv[])
{
    int i;
    int j;
    char **s_split;
    int k;

    if(argc < 2)
        return (1);
    i = 1;
    k = 0;
    while (i < argc)
    {
        s_split = ft_split(argv[i],' ');
        if (!s_split || !s_split[0])
        {
            free_split(s_split);
            write(2, "Error\n", 6);
            return (1);
        }
        while (s_split[k])
        {
            if(!(is_a_digit(s_split[k])))
            {
                free_split(s_split);
                exit_error();
            }
            long val = ft_atoi(s_split[k]);
            if (val > INT_MAX || val < INT_MIN)
            {
                free_split(s_split);
                exit_error();
            }       
            printf("%ld\n",val);
            k++;
        }
       free_split(s_split);
        i++;
    }
    return 0;
}*/