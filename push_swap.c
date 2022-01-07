
#include "push_swap.h"

int main(int argc, char* argv[])
{
    t_list  *stack_a;
    t_list  *stack_b;

    if (argc < 3)
        ft_perror_and_exit("Error\nYou should provide at least two integers");
    ft_get_stack_a(&stack_a, argv);
	ft_index_this_list(stack_a);
	ft_putstr_fd("Initial stack: \n", 1);
	ft_print_list_content(stack_a);
	if (ft_is_cir_sorted(stack_a))
	{
		ft_putstr_fd("\nThis stack is circularly sorted\n", 1);
//		ft_final_sort(&stack_a);
//		ft_lstclear(&stack_a, free);
//		return (0);
	}
	ft_presort(&stack_a, &stack_b);
	ft_little_cir_sort(&stack_a);
//	ft_move_back_from_stack_b(&stack_a, &stack_b);
//	ft_final_sort(&stack_a);

	ft_score_stack_b(stack_b, stack_a);
//	ft_print_list_content(stack_b);
	ft_putstr_fd("Stack before exit: \n", 1);
	ft_print_list_content(stack_a);

	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}

void    ft_perror_and_exit(const char *message)
{
    ft_putstr_fd(message, 2);
    exit(EXIT_FAILURE);
}

void    ft_print_list_content(t_list *lst)
{
    char    *cont;
    char	*score;
    char	*cost;

	ft_putstr_fd("val:\tscore:\tcost:\n", 1);
    while (lst)
    {
        cont = ft_itoa(*((int *)(lst->content)));
        ft_putstr_fd(cont, 1);
        ft_putstr_fd("\t\t", 1);
        free(cont);
        score = ft_itoa(lst->score);
		ft_putstr_fd(score, 1);
		ft_putstr_fd("\t\t", 1);
		free(score);
		cost = ft_itoa(lst->cost);
		ft_putstr_fd(cost, 1);
		free(cost);
		ft_putstr_fd("\n", 1);
        lst = lst->next;
    }
}
