/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rb_rrb_ra_rra_funcs.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:17:36 by stycho            #+#    #+#             */
/*   Updated: 2022/01/08 17:17:38 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_rb_ra(t_list *node, t_list **dst, t_list **src);
void	ft_move_rrb_ra(t_list *node, t_list **dst, t_list **src);
void	ft_move_rb_rra(t_list *node, t_list **dst, t_list **src);
void	ft_move_rrb_rra(t_list *node, t_list **dst, t_list **src);

void	ft_move_rb_ra(t_list *node, t_list **dst, t_list **src)
{
	int	rb_count;
	int	ra_count;

	rb_count = ft_get_rb_cost(*(int *)node->content, *src);
	ra_count = ft_get_ra_cost(*(int *)node->content, *dst);
	while (rb_count--)
		ft_rotate(src, "rb");
	while (ra_count--)
		ft_rotate(dst, "ra");
	ft_push2(dst, src, "pa");
}

void	ft_move_rrb_ra(t_list *node, t_list **dst, t_list **src)
{
	int	rrb_count;
	int	ra_count;

	rrb_count = ft_get_rrb_cost(*(int *)node->content, *src);
	ra_count = ft_get_ra_cost(*(int *)node->content, *dst);
	while (rrb_count--)
		ft_rev_rotate(src, "rrb", 0);
	while (ra_count--)
		ft_rotate(dst, "ra");
	ft_push2(dst, src, "pa");
}

void	ft_move_rb_rra(t_list *node, t_list **dst, t_list **src)
{
	int	rb_count;
	int	rra_count;

	rb_count = ft_get_rb_cost(*(int *)node->content, *src);
	rra_count = ft_get_rra_cost(*(int *)node->content, *dst);
	while (rb_count--)
		ft_rotate(src, "rb");
	while (rra_count--)
		ft_rev_rotate(dst, "rra", 1);
	ft_push2(dst, src, "pa");
}

void	ft_move_rrb_rra(t_list *node, t_list **dst, t_list **src)
{
	int	rrb_count;
	int	rra_count;

	rrb_count = ft_get_rrb_cost(*(int *)node->content, *src);
	rra_count = ft_get_rra_cost(*(int *)node->content, *dst);
	while (rrb_count--)
		ft_rev_rotate(src, "rrb", 0);
	while (rra_count--)
		ft_rev_rotate(dst, "rra", 1);
	ft_push2(dst, src, "pa");
}
