/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:05:47 by stycho            #+#    #+#             */
/*   Updated: 2022/01/05 19:05:48 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_to_stack(t_list *el_owner, t_list *elem, t_list **stack, int top)
{
	if (top == 1)
	{
		ft_push_head(el_owner, elem, stack);
	}
	else
		ft_push_back(el_owner, elem, stack);
}

void	ft_push_head(t_list *elem_owner, t_list *elem, t_list **stack)
{
	t_list	*cur_node;

	cur_node = elem_owner;
	if (cur_node->next == NULL)	// if len == 1
	{
		elem_owner = NULL;
		cur_node = NULL;
	}
	while (cur_node)			// if len > 1
	{
		if (cur_node->next->next == NULL
			&& *(int *)cur_node->next->content == *(int *)elem->content)
		{
			cur_node->next = NULL;
			break ;
		}
		if (*(int *)cur_node->next->content == *(int *)elem->content)
		{
			cur_node->next = elem->next;
			break ;
		}
		cur_node = cur_node->next;
	}
	ft_lstadd_front(stack, elem);
}

void	ft_push_back(t_list *elem_owner, t_list *elem, t_list **stack)
{
	t_list	*cur_node;

	cur_node = elem_owner;
	if (cur_node->next == NULL)	// if len == 1
	{
		elem_owner = NULL;
		cur_node = NULL;
	}
	while (cur_node)			// if len > 1
	{
		if (cur_node->next->next == NULL
			&& *(int *)cur_node->next->content == *(int *)elem->content)
		{
			cur_node->next = NULL;
			break ;
		}
		if (*(int *)cur_node->next->content == *(int *)elem->content)
		{
			cur_node->next = elem->next;
			break ;
		}
		cur_node = cur_node->next;
	}
	elem->next = NULL;
	ft_lstadd_back(stack, elem);
}
