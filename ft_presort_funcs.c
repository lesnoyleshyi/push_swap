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

void	ft_presort(t_list **stack_a, t_list **stack_b)
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
			ft_choose_rotate(stack_a, 0, a_len / 2, a_len - 1);
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

void	ft_choose_rotate(t_list **stack_a, int min, int med, int max)
{
	int		cost_ra;
	int		pos;
	int		last_durex_ind;
	t_list	*nod;

	nod = *stack_a;
	cost_ra = 0;
	while (nod && nod->score == min && nod->score == med && nod->score == max)
	{
		cost_ra++;
		nod = nod->next;
	}
	nod = *stack_a;
	pos = 0;
	while (nod)
	{
		if (nod->score == min || nod->score == med || nod->score == max)
			last_durex_ind = pos;
		nod = nod->next;
		pos += 1;
	}
	if (cost_ra >= ft_lstsize(*stack_a) - last_durex_ind)
		ft_rotate(stack_a, "ra");
	else
		ft_rev_rotate(stack_a, "rra", 1);
}
