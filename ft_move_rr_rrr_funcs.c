/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rr_rrr_funcs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:33:56 by stycho            #+#    #+#             */
/*   Updated: 2022/01/08 20:33:59 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_rr(t_list *node, t_list **dst, t_list **src);
void	ft_move_rrr(t_list *node, t_list **dst, t_list **src);

void	ft_move_rr(t_list *node, t_list **dst, t_list **src)
{
	int	rb_count;
	int	ra_count;
	int	rr_count;

	rb_count = ft_get_rb_cost(*(int *)node->content, *src);
	ra_count = ft_get_ra_cost(*(int *)node->content, *dst);
	rr_count = ft_get_rr_rrr_possible_count(rb_count, ra_count);
	while (rr_count--)
	{
		ft_rr(dst, src);
		rb_count--;
		ra_count--;
	}
	while (rb_count--)
		ft_rotate(src, "rb");
	while (ra_count--)
		ft_rotate(dst, "ra");
	ft_pa(dst, src);
}

void	ft_move_rrr(t_list *node, t_list **dst, t_list **src)
{
	int	rrb_count;
	int	rra_count;
	int	rrr_count;

	rrb_count = ft_get_rrb_cost(*(int *)node->content, *src);
	rra_count = ft_get_rra_cost(*(int *)node->content, *dst);
	rrr_count = ft_get_rr_rrr_possible_count(rrb_count, rra_count);
	while (rrr_count--)
	{
		ft_rrr(dst, src);
		rrb_count--;
		rra_count--;
	}
	while (rrb_count--)
		ft_rev_rotate(src, "rrb", 0);
	while (rra_count--)
		ft_rev_rotate(dst, "rra", 1);
	ft_pa(dst, src);
}
