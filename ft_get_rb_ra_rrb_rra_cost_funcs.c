/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_rb_ra_rrb_rra_cost_funcs.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:16:04 by stycho            #+#    #+#             */
/*   Updated: 2022/01/10 18:16:05 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_rb_cost(int el_value, t_list *stack_b)
{
	int		rb_cost;
	t_list	*node;

	node = stack_b;
	rb_cost = 0;
	while (node)
	{
		if (*(int *)node->content == el_value)
			return (rb_cost);
		node = node->next;
		rb_cost += 1;
	}
	return (2147482000);
}

int	ft_get_rrb_cost(int el_value, t_list *stack_b)
{
	int		list_len;
	int		pos;
	t_list	*node;

	node = stack_b;
	list_len = ft_lstsize(stack_b);
	pos = 0;
	while (node)
	{
		if (*(int *)node->content == el_value)
		{
			if (pos == 0)
				return (0);
			return (list_len - pos);
		}
		node = node->next;
		pos += 1;
	}
	return (2147482000);
}

int	ft_get_ra_cost(int el_value, t_list *stack_a)
{
	int		appr_num;
	int		pos;
	t_list	*node;

	appr_num = ft_get_appropriate_num(stack_a, el_value);
	node = stack_a;
	pos = 0;
	while (node)
	{
		if (*(int *)node->content == appr_num)
			return (pos);
		node = node->next;
		pos += 1;
	}
	return (2147482000);
}

int	ft_get_rra_cost(int el_value, t_list *stack_a)
{
	t_list	*node;
	int		appr_num;
	int		list_len;
	int		pos;

	appr_num = ft_get_appropriate_num(stack_a, el_value);
	list_len = ft_lstsize(stack_a);
	pos = 0;
	node = stack_a;
	while (node)
	{
		if (*(int *)node->content == appr_num)
		{
			if (pos == 0)
				return (0);
			return (list_len - pos);
		}
		node = node->next;
		pos += 1;
	}
	return (2147482000);
}

int	ft_get_appropriate_num(t_list *stack, int val)
{
	t_list	*node;
	t_list	*next;
	int		cur_val;
	int		next_val;
	int		first_val;

	node = stack;
	while (node && node->next)
	{
		next = node->next;
		cur_val = *(int *)node->content;
		next_val = *(int *)next->content;
		if (cur_val < val && next_val > val)
			return (next_val);
		node = node->next;
	}
	first_val = *(int *)stack->content;
	return (first_val);
}
