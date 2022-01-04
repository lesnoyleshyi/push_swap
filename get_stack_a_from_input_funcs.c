
#include "push_swap.h"

void    ft_get_stack_a(t_list **lst, char *argv[])
{
    int     i;
    int     number;
    int     *heap_number;
    t_list  *node;

    i = 1;
    while (argv[i])
    {
        number = ft_long_atoi(argv[i]);
        if (i > 1)
            ft_is_num_already_in_list(number, *lst);
        heap_number = (int *)malloc(sizeof(int));
        if (!heap_number)
            ft_perror_and_exit("Error\nCan't allocate memory");
        *heap_number = number;
        node = ft_lstnew(heap_number);
        if (!node)
            ft_perror_and_exit("Error\nCan't allocate memory");
        if (i == 1)
            *lst = node;
        else
            ft_lstadd_back(lst, node);
        i++;
    }
}

void    ft_is_num_already_in_list(int number, t_list *lst)
{
    while (lst != NULL)
    {
        if (lst->content && *((int *) (lst->content)) == number)
            ft_perror_and_exit("Error\nFound duplicated number");
        lst = lst->next;
    }
}

int ft_long_atoi(const char *str)
{
    int         minus_status;
    long long   res;

    ft_valid_number(str);
    res = 0;
    minus_status = 1;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            minus_status = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        res = (res * 10 + (*str++ - '0'));
        if (minus_status == 1 && res > 2147483647)
            ft_perror_and_exit("Error\nNumber can't exceed int range");
        if (minus_status == -1 && res > 2147483648)
            ft_perror_and_exit("Error\nNumber can't exceed int range");
    }
    return ((int)(res * minus_status));
}

void    ft_valid_number(const char *str)
{
    int i;

    i = 0;
    if (!((str[i] == '+') || (str[i] == '-') || ft_isdigit(str[i])))
        ft_perror_and_exit("Error\nInvalid argument - not a number");
    while (str[++i])
        if (!(ft_isdigit(str[i])))
            ft_perror_and_exit("Error\nInvalid argument - not a number");
}
