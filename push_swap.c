#include "push_swap.h"

void all_algo(t_stack **a, t_stack **b, int len)
{
    if (len == 0 || len == 1)
        return ;
    if(len < 3)
        algo_trie_2(a);
    if(len == 3)
        algo_trie_3(a);
    if (len <= 20)
        algo_trie_petite_liste(a, b, len);
    if (len > 20)
        algo_trie_grande_liste(a, b, len);
}

int main(int argc, char *argv[])
{
    int i;
    char **s_split;
    t_stack *a;
    t_stack *b;

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
    index_stack(&a);
    all_algo(&a, &b, length_stack(a));
    free_stack(&a);
    free_stack(&b);
    return (0);
}


/*
#include <stdio.h>

void afficherListe(t_stack *maListe)
{
    while(maListe)
    {
        printf("%ld\n",maListe->value);
        maListe = maListe->next;
    }
}
void afficherindex(t_stack *maListe)
{
    while(maListe)
    {
        printf("index :%d valeur : %ld\n",maListe->index,maListe->value);
        maListe = maListe->next;
    }
}*/