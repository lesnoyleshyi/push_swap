/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:17:12 by stycho            #+#    #+#             */
/*   Updated: 2022/01/05 12:17:13 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index_this_list(t_list *list_to_index)
{
	t_list	*sorted_list;

	sorted_list = ft_bubble_sort_ll(list_to_index);
	ft_write_to_score_field(list_to_index, sorted_list);
	ft_lstclear(&sorted_list, free);
}

void	ft_write_to_score_field(t_list *list_to_index, t_list *sorted_list)
{
	t_list	*node_to_ind;
	t_list	*sorted_ll_node;
	int		i;

	node_to_ind = list_to_index;
	while (node_to_ind)
	{
		sorted_ll_node = sorted_list;
		i = 0;
		while (sorted_ll_node)
		{
			if (*(int *)node_to_ind->content == *(int *)sorted_ll_node->content)
			{
				node_to_ind->score = i;
				break ;
			}
			sorted_ll_node = sorted_ll_node->next;
			i++;
		}
		node_to_ind = node_to_ind->next;
	}
}
