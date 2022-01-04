
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
void    ft_is_num_already_in_list(int number, t_list **lst);
void    ft_get_stack_a(t_list **head, char *argv[]);
void    ft_perror_and_exit(const char *message);
void    ft_valid_number(const char *str);
int     ft_long_atoi(const char *str);
void    ft_print_list_content(t_list *lst);
#endif
