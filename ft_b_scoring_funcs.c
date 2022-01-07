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

	node = stack_b;
	while (node)
	{
		ft_get_all_costs(node, stack_b, stack_a);
		node = node->next;
	}
}

void	ft_get_all_costs(t_list *elem, t_list *stack_b, t_list *stack_a)
{
	int cost_rb;
	int cost_rrb;
	int cost_ra;
	int	cost_rra;
	int min_cost;

	char *cost_rbch;
	char *cost_rrbch;
	char *cost_rach;
	char *cost_rrach;
	char *min_cost_ch;

	cost_rb = ft_get_rb_cost(*(int *)elem->content, stack_b);
	cost_rrb = ft_get_rrb_cost(*(int *)elem->content, stack_b);
	cost_ra = ft_get_ra_cost(*(int *)elem->content, stack_a);
	cost_rra = ft_get_rra_cost(*(int *)elem->content, stack_a);

	min_cost = cost_rb * (cost_rb <= cost_rrb) + cost_rrb * (cost_rrb < cost_rb)
			+ cost_ra * (cost_ra <= cost_rra) + cost_rra * (cost_rra < cost_ra);

	cost_rbch = ft_itoa(cost_rb);
	cost_rrbch = ft_itoa(cost_rrb);
	cost_rach = ft_itoa(cost_ra);
	cost_rrach = ft_itoa(cost_rra);
	min_cost_ch = ft_itoa(min_cost);
	ft_putstr_fd("costs for elem:\n", 1);
	ft_putstr_fd("cost rb: ", 1);
	ft_putstr_fd(cost_rbch, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("cost rrb: ", 1);
	ft_putstr_fd(cost_rrbch, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("cost ra: ", 1);
	ft_putstr_fd(cost_rach, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("cost rra: ", 1);
	ft_putstr_fd(cost_rrach, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("Result minimum cost: ", 1);
	ft_putstr_fd(min_cost_ch, 1);
	ft_putstr_fd("\n\n", 1);
	free(cost_rbch);
	free(cost_rrbch);
	free(cost_rach);
	free(cost_rrach);
	free(min_cost_ch);
}

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
	int 	appr_num;
	int		pos;
	t_list	*node;
	char	*apr_num;

	appr_num = ft_get_appropriate_num(stack_a, el_value);
	apr_num = ft_itoa(appr_num);
	ft_putstr_fd("Appropriate number: ", 1);
	ft_putstr_fd(apr_num, 1);
	ft_putstr_fd("\n", 1);
	free(apr_num);
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
	int 	cur_val;
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