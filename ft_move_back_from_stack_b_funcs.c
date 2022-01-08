/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_back_from_stack_b_funcs.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:00:54 by stycho            #+#    #+#             */
/*   Updated: 2022/01/07 22:00:55 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_get_cheapest_node(t_list *stack_b);
void	ft_cheapest_move(t_list *node_to_move, t_list **dst, t_list **src);
int	ft_make_choice(int rb, int ra, int rrb, int rra);
void	ft_choose_move(int choice, t_list *node, t_list **dst, t_list **src);
int ft_get_rr_rrr_possible_count(int rb, int ra);

void	ft_move_back_from_stack_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	t_list	*cheapest_node;
	char	*debug;
	char	*debug2;

	a = *stack_a;
	b = *stack_b;
	while (b)
	{
		ft_score_stack_b(*stack_b, *stack_a);
		cheapest_node = ft_get_cheapest_node(*stack_b);

		ft_putstr_fd("Value of cheapest node: ", 1);
		debug = ft_itoa(*(int *)cheapest_node->content);
		ft_putstr_fd(debug, 1);
		ft_putstr_fd("\n", 1);
		ft_putstr_fd("Score of cheapest node: ", 1);
		debug2 = ft_itoa(cheapest_node->cost);
		ft_putstr_fd(debug2, 1);
		ft_putstr_fd("\n", 1);
		free(debug2);

		ft_cheapest_move(cheapest_node, stack_a, stack_b);

		b = b->next;
	}
	return ;
}

t_list	*ft_get_cheapest_node(t_list *stack_b)
{
	int		min_cost;
	t_list	*cur_node;
	t_list	*cheapest_node;

	cur_node = stack_b;
	if (cur_node == NULL)
		return (NULL);
	min_cost = cur_node->cost;
	cheapest_node = cur_node;
	while (cur_node)
	{
		if (cur_node->cost < min_cost)
		{
			cheapest_node = cur_node;
			min_cost = cur_node->cost;
		}
		cur_node = cur_node->next;
	}
	return (cheapest_node);
}

void	ft_cheapest_move(t_list *node_to_move, t_list **dst, t_list **src)
{
	int	rb;
	int	ra;
	int	rrb;
	int rra;
	int	choice;

	rb = ft_get_rb_cost(*(int *)node_to_move->content, *src);
	ra = ft_get_ra_cost(*(int *)node_to_move->content, *src);
	rrb = ft_get_rrb_cost(*(int *)node_to_move->content, *dst);
	rra = ft_get_rra_cost(*(int *)node_to_move->content, *dst);
	choice = ft_make_choice(rb, ra, rrb, rra);
	ft_choose_move(choice, node_to_move, dst, src);
//	if ((rb != 0 && ra != 0) || (rrb != 0 && rra != 0))
//	{
//		choice = ft_make_rr_rrr_possible_choice(rb, ra, rrb, rra);
//		ft_rr_rrr_possible_move(choice, node_to_move, dst, src);
//	}
//	else
//	{
//		choice = ft_make_simple_choice(rb, ra, rrb, rra);
//		ft_simple_move(choice, node_to_move, dst, src);
//	}
	return ;
}

int	ft_make_choice(int rb, int ra, int rrb, int rra)
{
	int	rb_ra;
	int	rrb_ra;
	int	rb_rra;
	int	rrb_rra;

	rb_ra = rb + ra;
	rrb_ra = rrb + ra;
	rb_rra = rb + rra;
	rrb_rra = rrb + rra;
	while (1)
	{
		if ((rb_ra - ft_get_rr_rrr_possible_count(rb, ra)) == 0)
			return (5);
		if ((rrb_rra - ft_get_rr_rrr_possible_count(rrb, rra)) == 0)
			return (6);
		if (rb_ra-- == 0)
			return (1);
		if (rrb_ra-- == 0)
			return (2);
		if (rb_rra-- == 0)
			return (3);
		if (rrb_rra == 0)
			return (4);
	}
}

void	ft_choose_move(int choice, t_list *node, t_list **dst, t_list **src)
{
	if (choice == 1)
		ft_move_rb_ra(node, dst, src);
	if (choice == 2)
		ft_move_rrb_ra(node, dst, src);
	if (choice == 3)
		ft_move_rb_rra(node, dst, src);
	if (choice == 4)
		ft_move_rrb_rra(node, dst, src);
	if (choice == 5)
		ft_move_rr(node, dst, src);
	if (choice == 6)
		ft_move_rrr(node, dst, src);
}

//int	ft_get_min_rr_rrr_move_cost()
//{
//	int	rrr_min_cost;
//	int	rr_min_cost;
//
//	rr_min_cost = ft_get_rr_min_cost(ra, rb);
//	rrr_min_cost = ft_get_rrr_min_cost(rra, rrb);
//	if (rr_min_cost <= rrr_min_cost)
//		return (rr_min_cost);
//	else
//		return (rrr_min_cost);
//}

int ft_get_rr_rrr_possible_count(int rb, int ra)
{
	int	rr_count;

	rr_count = 0;
	while (ra > 0 && rb > 0)
	{
		rr_count++;
		ra--;
		rb--;
	}
	return (rr_count);
}
