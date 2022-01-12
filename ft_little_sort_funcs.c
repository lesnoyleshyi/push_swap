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

void	ft_little_cir_sort(t_list **stack, char *sa_or_sb)
{
	int	stack_len;

	stack_len = ft_lstsize(*stack);
	if (stack_len == 2)
		ft_sort_two(stack, sa_or_sb);
	else
		ft_cir_sort_three(stack, sa_or_sb);
}

void	ft_sort_two(t_list **stack, char *sa_or_sb)
{
	t_list	*first_node;
	t_list	*second_node;

	first_node = *stack;
	second_node = (*stack)->next;
	if (*(int *)second_node->content < *(int *)first_node->content)
		ft_swap(stack, sa_or_sb);
}

void	ft_sort_three(t_list **stack, char *sa_or_sb)
{
	ft_cir_sort_three(stack, sa_or_sb);
	ft_final_sort(stack);
}

void	ft_cir_sort_three(t_list **stack, char *sa_or_sb)
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
	ft_swap(stack, sa_or_sb);
}

void	ft_sort_five(t_list **stack_b, t_list **stack_a)
{
	int	min_val;
	int	ra_cost;
	int	rra_cost;

	while (ft_lstsize(*stack_a) > 3)
	{
		min_val = ft_get_min_val(*stack_a);
		ra_cost = ft_get_rb_cost(min_val, *stack_a);
		rra_cost = ft_get_rrb_cost(min_val, *stack_a);
		if (ra_cost <= rra_cost)
			while (ra_cost--)
				ft_rotate(stack_a, "ra");
		else
			while (rra_cost--)
				ft_rev_rotate(stack_a, "rra", 1);
		ft_push(stack_b, stack_a, "pb");
	}
	if (*(int *)(*stack_b)->content < *(int *)(*stack_b)->next->content)
		ft_rotate(stack_b, "rb");
	ft_sort_three(stack_a, "sa");
	ft_push(stack_a, stack_b, "pa");
	ft_push(stack_a, stack_b, "pa");
}
