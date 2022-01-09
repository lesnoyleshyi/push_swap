/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_a_from_input_funcs.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:27:09 by stycho            #+#    #+#             */
/*   Updated: 2022/01/05 14:27:10 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        ft_is_num_already_in_list(number, lst);
        heap_number = (int *)malloc(sizeof(int));
        if (!heap_number)
            ft_perror_and_exit("Error\nCan't allocate memory\n");
        *heap_number = number;
        node = ft_lstnew(heap_number);
        if (!node)
            ft_perror_and_exit("Error\nCan't allocate memory\n");
        ft_lstadd_back(lst,  node);
        i++;
    }
}

void    ft_is_num_already_in_list(int number, t_list **lst)
{
    t_list	*p_node;

    p_node = *lst;
	while (p_node != NULL)
    {
		if (p_node->content && *((int *)(p_node->content)) == number)
            ft_perror_and_exit("Error\nFound duplicated number\n");
		p_node = p_node->next;
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
            ft_perror_and_exit("Error\nNumber can't exceed int range\n");
        if (minus_status == -1 && res > 2147483648)
            ft_perror_and_exit("Error\nNumber can't exceed int range\n");
    }
    return ((int)(res * minus_status));
}

void    ft_valid_number(const char *str)
{
    int i;

    i = 0;
    if (!((str[i] == '+') || (str[i] == '-') || ft_isdigit(str[i])))
        ft_perror_and_exit("Error\nInvalid argument - not a number\n");
    while (str[++i])
        if (!(ft_isdigit(str[i])))
            ft_perror_and_exit("Error\nInvalid argument - not a number\n");
}
