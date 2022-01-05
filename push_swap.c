
#include "push_swap.h"

typedef	struct {
	int min_score;
	int med_score;
	int max_score;
}	stack_meta;

int main(int argc, char* argv[])
{
    t_list  *stack_a;
    t_list  *stack_b;

    if (argc <= 2)
        ft_perror_and_exit("Error\nYou should provide at least two integers");
    ft_get_stack_a(&stack_a, argv);
	ft_index_this_list(stack_a);
	ft_presort(&stack_a, &stack_b);
	ft_print_list_content(stack_a);
	ft_print_list_content(stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}

void    ft_perror_and_exit(const char *message)
{
    ft_putstr_fd(message, 2);
    exit(EXIT_FAILURE);
}

void    ft_print_list_content(t_list *lst)
{
    char    *str;
    char	*index;

	ft_putstr_fd("val:\tind:\n", 1);
    while (lst)
    {
        str = ft_itoa(*((int *)(lst->content)));
        ft_putstr_fd(str, 1);
        ft_putstr_fd("\t", 1);
        free(str);
        index = ft_itoa(lst->score);
		ft_putstr_fd(index, 1);
		ft_putstr_fd("\n", 1);
		free(index);
        lst = lst->next;
    }
}
