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

void	ft_rb(t_list **stack_b);
void	ft_rrb(t_list **stack_b);
void	ft_ra(t_list **stack_a);
void	ft_rra(t_list **stack_a);

void	ft_rb(t_list **stack_b)
{
	t_list	*node;
	t_list	*last_node;

	node = *stack_b;
	if (node == NULL || node->next == NULL)
		return ;
	while (node)
	{
		if (node->next == NULL)
			last_node = node;
		node = node->next;
	}
	last_node->next = *stack_b;
	*stack_b = (*stack_b)->next;
	last_node->next->next = NULL;
	ft_putstr_fd("rb\n", 1);
}

void	ft_rrb(t_list **stack_b)
{
	t_list	*b;

	b = *stack_b;
	ft_putstr_fd("rrb\n", 1);
}

void	ft_ra(t_list **stack_a)
{
	t_list	*node;
	t_list	*last_node;

	node = *stack_a;
	if (node == NULL || node->next == NULL)
		return ;
	while (node)
	{
		if (node->next == NULL)
			last_node = node;
		node = node->next;
	}
	last_node->next = *stack_a;
	*stack_a = (*stack_a)->next;
	last_node->next->next = NULL;
	ft_putstr_fd("ra\n", 1);
}

void	ft_rra(t_list **stack_a)
{
	t_list	*a;

	a = *stack_a;
	ft_putstr_fd("rra\n", 1);
}
