/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_ra_rrb_rra_funcs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:56:09 by stycho            #+#    #+#             */
/*   Updated: 2022/01/08 20:56:10 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack, char *rb_or_ra)
{
	t_list	*node;
	t_list	*last_node;

	if (stack == NULL || *stack == NULL)
		return ;
	node = *stack;
	while (node)
	{
		if (node->next == NULL)
			last_node = node;
		node = node->next;
	}
	last_node->next = *stack;
	*stack = (*stack)->next;
	last_node->next->next = NULL;
	if (rb_or_ra)
	{
		ft_putstr_fd(rb_or_ra, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	ft_rev_rotate(t_list **stack, char *rrb_or_rra, int b_a_switch_rrr)
{
	t_list	*node;

	if (stack == NULL || *stack == NULL)
		return ;
	node = *stack;
	if (node->next == NULL)
	{
		ft_sb_sa_switch(stack, rrb_or_rra, b_a_switch_rrr);
		return ;
	}
	while (node && node->next)
	{
		if (node->next->next == NULL)
		{
			node->next->next = *stack;
			*stack = node->next;
			node->next = NULL;
		}
		node = node->next;
	}
	if (rrb_or_rra)
	{
		ft_putstr_fd(rrb_or_rra, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	ft_swap(t_list **stack, char *sb_or_sa)
{
	t_list	*first_node;
	t_list	*second_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first_node = *stack;
	second_node = (*stack)->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*stack = second_node;
	if (sb_or_sa)
	{
		ft_putstr_fd(sb_or_sa, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	ft_sb_sa_switch(t_list **stack, char *rrb_or_rra, int b_a_switch_rrr)
{
	if (rrb_or_rra == NULL)
	{
		if (b_a_switch_rrr == 0)
			ft_swap(stack, "sb");
		else
			ft_swap(stack, "sa");
		return ;
	}
	if (ft_strncmp(rrb_or_rra, "rrb", 4) == 0)
		ft_swap(stack, "sb");
	else
		ft_swap(stack, "sa");
}
