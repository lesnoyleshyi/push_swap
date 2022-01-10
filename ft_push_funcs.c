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

//void	ft_push(t_list **el_owner, t_list *elem, t_list **stack, int top)
//{
////	ft_putstr_fd("-------\nStack_a before push: \n", 1);
////	ft_print_list_content(*el_owner);
////	ft_putstr_fd("Stack_b before push: \n", 1);
////	ft_print_list_content(*stack);
////	ft_putstr_fd("-------\n", 1);
//	if (top == 1)
//	{
//		ft_push_head(el_owner, elem, stack);
//	}
//	else
//		ft_push_back(el_owner, elem, stack);
////	ft_putstr_fd("+++++++\nStack_a after push: \n", 1);
////	ft_print_list_content(*el_owner);
////	ft_putstr_fd("Stack_b after push: \n", 1);
////	ft_print_list_content(*stack);
////	ft_putstr_fd("+++++++\n", 1);
//}
//
//void	ft_push_head(t_list **elem_owner, t_list *elem, t_list **stack)
//{
//	ft_remove_from_stack(elem_owner, elem);
//	ft_lstadd_front(stack, elem);
//	ft_putstr_fd("pb\n", 1);
//}
//
//void	ft_push_back(t_list **elem_owner, t_list *elem, t_list **stack)
//{
//	ft_remove_from_stack(elem_owner, elem);
//	elem->next = NULL;
//	if (!(stack == NULL || *stack == NULL))
//		ft_putstr_fd("rb\n", 1);
//	ft_lstadd_back(stack, elem);
//	ft_putstr_fd("pb\n", 1);
//
//}
//
//void	ft_remove_from_stack(t_list **elem_owner, t_list *elem)
//{
//	t_list	*cur_node;
//
//	cur_node = *elem_owner;
//	if (elem == NULL || *elem_owner == NULL)
//		return ;
//	if (cur_node == elem)
//	{
//		ft_remove_from_top(elem_owner);
//		return ;
//	}
//	while (cur_node && cur_node->next)
//	{
//		if (*(int *)cur_node->next->content == *(int *)elem->content)
//		{
//			cur_node->next = cur_node->next->next;
//			break ;
//		}
//		cur_node = cur_node->next;
//	}
//}
//
//void	ft_remove_from_top(t_list **list)
//{
//	if (*list == NULL)
//		return ;
//	if ((*list)->next == NULL)
//	{
//		*list = NULL;
//		return ;
//	}
//	*list = (*list)->next;
//}

void	ft_push2(t_list **dst, t_list **src, char* pb_or_pa)
{
	t_list	*top_src_node;

	if (src == NULL || *src == NULL)
		return ;
	top_src_node = *src;
	*src = top_src_node->next;
	top_src_node->next = *dst;
	*dst = top_src_node;
	ft_putstr_fd(pb_or_pa, 1);
	ft_putstr_fd("\n", 1);
}
