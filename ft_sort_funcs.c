/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:47:33 by stycho            #+#    #+#             */
/*   Updated: 2022/01/04 22:47:41 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_bubble_sort_ll(t_list *unsorted_list)
{
	t_list	*cur_node;
	t_list	*next_node;
	t_list	*sorted_list;

	sorted_list = ft_dup_list(unsorted_list);
	cur_node = sorted_list;
	while (cur_node)
	{
		next_node = cur_node->next;
		while (next_node)
		{
			if (*(int *)next_node->content < *(int *)cur_node->content)
				ft_swap_nodes_content(cur_node, next_node);
			next_node = next_node->next;
		}
		cur_node = cur_node->next;
	}
	return (sorted_list);
}

t_list	*ft_dup_list(t_list *unsorted_list)
{
	t_list	*orig_node;
	t_list	*new_node;
	t_list	*sorted_list;
	int		*copied_content;

	sorted_list = NULL;
	orig_node = unsorted_list;
	while (orig_node != NULL)
	{
		copied_content = (int *)malloc(sizeof(int));
		*copied_content = *(int *)orig_node->content;
		new_node = ft_lstnew(copied_content);
		ft_lstadd_back(&sorted_list, new_node);
		orig_node = orig_node->next;
	}
	return (sorted_list);
}

void	ft_swap_nodes_content(t_list *cur_node, t_list *next_node)
{
	int	dummy;

	dummy = *(int *)cur_node->content;
	*(int *)cur_node->content = *(int *)next_node->content;
	*(int *)next_node->content = dummy;
}
