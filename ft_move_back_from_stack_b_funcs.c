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

	return ;
}