
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
void    ft_is_num_already_in_list(int number, t_list **lst);
void    ft_get_stack_a(t_list **head, char *argv[]);
void    ft_perror_and_exit(const char *message);
void    ft_valid_number(const char *str);
int     ft_long_atoi(const char *str);
void    ft_print_list_content(t_list *lst);

t_list	*ft_dup_list(t_list *unsorted_list);
t_list *ft_bubble_sort_ll(t_list *unsorted_list);
void	ft_swap_nodes_content(t_list *cur_node, t_list *next_node);
#endif
