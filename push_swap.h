#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
    long value;
    int index;
    struct s_stack *next;
} t_stack;

int is_a_digit(char *s);
void inserer_node(t_stack **pile_a, long value);
void free_split(char **s_split);
void free_stack(t_stack **stack);
void exit_error(char **s_split,t_stack **pile_a);
void s_split_empty(char **s_split,t_stack **pile_a);
long is_duplicate(t_stack *pile_a, long n);
void value_atoi(char **s_split,t_stack **pile_a);
long ft_atoi(char *str);
int count_words(char *str, char c);
char **ft_split(char *str, char sep);
void sa(t_stack **stack, int n);
void sb(t_stack **stack, int n);
void ss(t_stack **a, t_stack **b);
void ra(t_stack **stack, int n);
void rb(t_stack **stack, int n);
void rr(t_stack **a, t_stack **b);
void rra(t_stack **stack, int n);
void pb(t_stack **a,t_stack **b);
void pa(t_stack **b,t_stack **a);
void algo_trie_3(t_stack **a);
int length_stack(t_stack *stack);
void algo_trie_2(t_stack **a);
void all_algo(t_stack **a, t_stack **b, int len);
void algo_trie_4(t_stack **a,t_stack **b);
void algo_trie_5(t_stack **a,t_stack **b);
int is_sorted(t_stack *a);
#endif