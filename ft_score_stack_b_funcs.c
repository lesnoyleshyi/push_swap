/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_scoring_funcs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:04:29 by stycho            #+#    #+#             */
/*   Updated: 2022/01/06 20:04:30 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_score_stack_b(t_list *stack_b, t_list *stack_a)
{
	t_list	*node;
	int		min_node_cost;

	node = stack_b;
	while (node)
	{
		min_node_cost = ft_get_min_cost(node, stack_b, stack_a);
		node->score = min_node_cost;
		node = node->next;
	}
}

int	ft_get_min_cost(t_list *elem, t_list *stack_b, t_list *stack_a)
{
	int	cost_rb;
	int	cost_rrb;
	int	cost_ra;
	int	cost_rra;
	int	min_cost;

	cost_rb = ft_get_rb_cost(*(int *)elem->content, stack_b);
	cost_rrb = ft_get_rrb_cost(*(int *)elem->content, stack_b);
	cost_ra = ft_get_ra_cost(*(int *)elem->content, stack_a);
	cost_rra = ft_get_rra_cost(*(int *)elem->content, stack_a);
	min_cost = cost_rb * (cost_rb <= cost_rrb) + cost_rrb * (cost_rrb < cost_rb)
		+ cost_ra * (cost_ra <= cost_rra) + cost_rra * (cost_rra < cost_ra);
	return (min_cost);
}
