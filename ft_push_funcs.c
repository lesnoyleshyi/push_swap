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

void	ft_push(t_list **el_owner, t_list *elem, t_list **stack, int top)
{
	if (top == 1)
	{
		ft_push_head(el_owner, elem, stack);
	}
	else
		ft_push_back(el_owner, elem, stack);
}

void	ft_push_head(t_list **elem_owner, t_list *elem, t_list **stack)
{
	ft_remove_from_stack(elem_owner, elem);
	ft_lstadd_front(stack, elem);
	ft_putstr_fd("pb\n", 1);
}

void	ft_push_back(t_list **elem_owner, t_list *elem, t_list **stack)
{
	ft_remove_from_stack(elem_owner, elem);
	elem->next = NULL;
	ft_lstadd_back(stack, elem);
	ft_putstr_fd("rb\n", 1);
	ft_putstr_fd("pb\n", 1);
}

void	ft_remove_from_stack(t_list **elem_owner, t_list *elem)
{
	t_list	*cur_node;

	cur_node = *elem_owner;
	if (elem == NULL || *elem_owner == NULL)
		return ;
	if (cur_node == elem)
	{
		ft_remove_from_top(elem_owner);
		return ;
	}
	while (cur_node && cur_node->next)
	{
		if (*(int *)cur_node->next->content == *(int *)elem->content)
		{
			cur_node->next = cur_node->next->next;
			break ;
		}
		cur_node = cur_node->next;
	}
}

void	ft_remove_from_top(t_list **list)
{
	if (*list == NULL)
		return ;
	if ((*list)->next == NULL)
	{
		*list = NULL;
		return ;
	}
	*list = (*list)->next;
}
