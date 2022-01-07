/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_little_sort_funcs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:52:28 by stycho            #+#    #+#             */
/*   Updated: 2022/01/07 13:52:29 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_little_cir_sort(t_list **stack)
{
	int	stack_len;

	stack_len = ft_lstsize(*stack);
	if (stack_len == 2)
		ft_sort_two(stack);
	else
		ft_cir_sort_three(stack);
}

void	ft_sort_two(t_list **stack)
{
	t_list	*first_node;
	t_list	*second_node;

	first_node = *stack;
	second_node = (*stack)->next;
	if (*(int *)second_node->content < *(int *)first_node->content)
	{
		*stack = second_node;
		(*stack)->next = first_node;
		(*stack)->next->next = NULL;
	}
}

void	ft_cir_sort_three(t_list **stack)
{
	int		v1;
	int		v2;
	int		v3;

	v1 = *(int *)(*stack)->content;
	v2 = *(int *)((*stack)->next->content);
	v3 = *(int *)((*stack)->next->next->content);
	if (!(((v1 > v2) && (v2 > v3))
			|| ((v1 < v2) && (v2 > v3) && (v3 > v1))
			|| ((v1 > v2) && (v2 < v3) && (v3 > v1))))
		return ;
	ft_swap_top(stack);
}

void	ft_swap_top(t_list **stack)
{
	t_list	*first_node;
	t_list	*second_node;

	first_node = *stack;
	second_node = (*stack)->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*stack = second_node;
}
