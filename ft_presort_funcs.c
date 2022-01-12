/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presort_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:59:41 by stycho            #+#    #+#             */
/*   Updated: 2022/01/05 22:59:43 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_presort(t_list **stack_b, t_list **stack_a)
{
	int	top_score;
	int	cur_len;
	int	a_len;

	a_len = ft_lstsize(*stack_a);
	cur_len = a_len;
	while (cur_len > 3)
	{
		top_score = (*stack_a)->score;
		if (top_score == 0 || top_score == a_len - 1 || top_score == a_len / 2)
		{
			ft_rotate(stack_a, "ra");
			continue ;
		}
		if (top_score < a_len / 2)
			ft_push(stack_b, stack_a, "pb");
		else
		{
			ft_push(stack_b, stack_a, "pb");
			if (ft_lstsize(*stack_b) > 2)
				ft_rotate(stack_b, "rb");
		}
		cur_len = ft_lstsize(*stack_a);
	}
}
