/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_cir_sorted_funcs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:54:25 by stycho            #+#    #+#             */
/*   Updated: 2022/01/07 17:54:26 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_n1(int *p_flg, t_list **p_lnode, t_list **p_node, t_list *stack);
int		ft_n2(int next_val, int min_val, int flag, t_list *last_node);

int	ft_is_cir_sorted(t_list *stack)
{
	int		min_val;
	t_list	*node;
	t_list	*lat_node;
	int		ol;

	min_val = ft_get_min_val(stack);
	node = stack;
	while (node)
	{
		if (*(int *)node->content == min_val)
			break ;
		node = node->next;
	}
	ol = 0;
	while (node)
	{
		if (node->next == NULL)
			ft_n1(&ol, &last_node, &node, stack);
		if (*(int *)node->content > *(int *)node->next->content)
			return (ft_n2(*(int *)node->next->content, min_val, ol, last_node));
		node = node->next;
	}
	return (0);
}

int	ft_get_min_val(t_list *stack)
{
	int		min_val;
	t_list	*node;
//	char				*deb;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	node = stack;
	min_val = *(int *)node->content;
	while (node)
	{
		if (*(int *)node->content < min_val)
			min_val = *(int *)node->content;
		node = node->next;
	}
//
//	deb = ft_itoa(min_val);
//	ft_putstr_fd("\nMin value of stack: ", 1);
//	ft_putstr_fd(deb, 1);
//	ft_putstr_fd("\n", 1);
//	free(deb);
	return (min_val);
}

void	ft_n1(int *p_flg, t_list **p_lnode, t_list **p_node, t_list *stack)
{
	*p_flg = 1;
	*p_lnode = *p_node;
	(*p_node)->next = stack;
}

int	ft_n2(int next_val, int min_val, int flag, t_list *last_node)
{
	if (next_val != min_val)
	{
		if (flag)
			last_node->next = NULL;
		return (0);
	}
	if (next_val == min_val)
	{
		if (flag)
			last_node->next = NULL;
		return (1);
	}
	return (0);
}
