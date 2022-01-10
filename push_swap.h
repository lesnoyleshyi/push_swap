/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:01:59 by stycho            #+#    #+#             */
/*   Updated: 2022/01/10 19:02:01 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

void	ft_is_num_already_in_list(int number, t_list **lst);
void	ft_get_stack_a(t_list **head, char *argv[]);
void	ft_perror_and_exit(const char *message);
void	ft_valid_number(const char *str);
int		ft_long_atoi(const char *str);
void	ft_print_list_content(t_list *lst);

t_list	*ft_dup_list(t_list *unsorted_list);
t_list	*ft_bubble_sort_ll(t_list *unsorted_list);
void	ft_swap_nodes_content(t_list *cur_node, t_list *next_node);

void	ft_index_this_list(t_list *list_to_index);
void	ft_write_to_score_field(t_list *list_to_index, t_list *sorted_list);

void	ft_presort(t_list **stack_a, t_list **stack_b);

void	ft_score_stack_b(t_list *stack_b, t_list *stack_a);
int		ft_get_rb_cost(int el_value, t_list *stack_b);
int		ft_get_rrb_cost(int el_value, t_list *stack_b);
int		ft_get_ra_cost(int el_value, t_list *stack_a);
int		ft_get_rra_cost(int el_value, t_list *stack_a);
int		ft_get_appropriate_num(t_list *stack, int val);
int		ft_get_min_cost(t_list *elem, t_list *stack_b, t_list *stack_a);

void	ft_little_cir_sort(t_list **stack, char *sa_or_sb);
void	ft_cir_sort_three(t_list **stack, char *sa_or_sb);
void	ft_sort_two(t_list **stack, char *sa_or_sb);

int		ft_is_cir_sorted(t_list *stack);
int		ft_get_min_val(t_list *stack);
void	ft_n1(int *p_flg, t_list **p_lnode, t_list **p_node, t_list *stack);
int		ft_n2(int next_val, int min_val, int flag, t_list *last_node);

void	ft_move_back_from_stack_b(t_list **stack_a, t_list **stack_b);

t_list	*ft_get_cheapest_node(t_list *stack_b);
void	ft_cheapest_move(t_list *node_to_move, t_list **dst, t_list **src);
int		ft_make_choice(int rb, int ra, int rrb, int rra);
void	ft_choose_move(int choice, t_list *node, t_list **dst, t_list **src);
int		ft_get_rr_rrr_possible_count(int rb, int ra);

void	ft_move_rb_ra(t_list *node, t_list **dst, t_list **src);
void	ft_move_rrb_ra(t_list *node, t_list **dst, t_list **src);
void	ft_move_rb_rra(t_list *node, t_list **dst, t_list **src);
void	ft_move_rrb_rra(t_list *node, t_list **dst, t_list **src);
void	ft_move_rr(t_list *node, t_list **dst, t_list **src);
void	ft_move_rrr(t_list *node, t_list **dst, t_list **src);

void	ft_rotate(t_list **stack, char *rb_or_ra);
void	ft_rev_rotate(t_list **stack, char *rrb_or_rra, int b_a_switch_rrr);
void	ft_swap(t_list **stack, char *sa_or_sb);
void	ft_sb_sa_switch(t_list **stack, char *rrb_or_rra, int b_a_switch_rrr);
void	ft_push(t_list **dst, t_list **src, char *pb_or_pa);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);

void	ft_final_sort(t_list **stack);

#endif
