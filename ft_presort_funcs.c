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
	int		list_len;
	t_list	*cur_st_a_node;
	t_list	*next_node;

	list_len = ft_lstsize(*stack_a);
	cur_st_a_node = *stack_a;
	while (cur_st_a_node)
	{
		next_node = cur_st_a_node->next;
		if (cur_st_a_node->score != 0 && cur_st_a_node->score != list_len - 1
			&& cur_st_a_node->score != list_len / 2)
		{
			if ((cur_st_a_node->score) < (list_len / 2))
			{
				ft_push(stack_a, cur_st_a_node, stack_b, 1);
				cur_st_a_node = next_node;
				continue ;
			}
			else
			{
				ft_push(stack_a, cur_st_a_node, stack_b, 0);
				cur_st_a_node = next_node;
				continue ;
			}
		}
		cur_st_a_node = cur_st_a_node->next;
		ft_putstr_fd("ra\n", 1);
	}
}

void	ft_presort2(t_list **stack_a, t_list **stack_b)
{
	int	st_a_len;
	int	cur_len;

	st_a_len = ft_lstsize(*stack_a);
	cur_len = st_a_len;
	while (st_a_len > 3)
	{
		if ((*stack_a)->score == 0 || (*stack_a)->score == st)
		st_a_len = ft_lstsize(*stack_a);
	}
	//надо дописать вот тут
}
