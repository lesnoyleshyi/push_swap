
#include "push_swap.h"

int main(int argc, char* argv[])
{
    t_list  *stack_a;
//    t_list  *stack_b;

    if (argc <= 2)
        ft_perror_and_exit("Error\nYou should provide at least two integers");
    ft_get_stack_a(&stack_a, argv);
    ft_print_list_content(stack_a);
	ft_lstclear(&stack_a, free);
}

void    ft_perror_and_exit(const char *message)
{
    ft_putstr_fd(message, 2);
    exit(EXIT_FAILURE);
}

void    ft_print_list_content(t_list *lst)
{
    char    *str;

    while (lst)
    {
        str = ft_itoa(*((int *)(lst->content)));
        ft_putstr_fd(str, 1);
        ft_putstr_fd("\n", 1);
        free(str);
        lst = lst->next;
    }
}
