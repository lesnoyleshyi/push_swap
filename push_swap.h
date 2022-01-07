
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

void	ft_index_this_list(t_list *list_to_index);
void	ft_write_to_score_field(t_list *list_to_index, t_list *sorted_list);

void	ft_push_head(t_list **elem_owner, t_list *elem, t_list **stack);
void	ft_push_back(t_list **elem_owner, t_list *elem, t_list **stack);
void	ft_push(t_list **el_owner, t_list *elem, t_list **stack, int top);
void	ft_remove_from_stack(t_list **elem_owner, t_list *elem);
void	ft_remove_from_top(t_list **list);

void	ft_presort(t_list **stack_a, t_list **stack_b);

void	ft_score_stack_b(t_list *stack_b, t_list *stack_a);
int	ft_get_min_cost(t_list *elem, t_list *stack_b, t_list *stack_a);
int	ft_get_rb_cost(int el_value, t_list *stack_b);
int	ft_get_rrb_cost(int el_value, t_list *stack_b);
int	ft_get_ra_cost(int el_value, t_list *stack_a);
int	ft_get_rra_cost(int el_value, t_list *stack_a);
int	ft_get_appropriate_num(t_list *stack, int val);

void	ft_little_sort(t_list **stack);
void	ft_sort_three(t_list **stack);
void	ft_sort_two(t_list **stack);
#endif
