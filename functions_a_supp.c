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