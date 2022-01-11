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

void	ft_push(t_list **dst, t_list **src, char *pb_or_pa)
{
	t_list	*top_src_node;

	if (src == NULL || *src == NULL)
		return ;
	top_src_node = *src;
	*src = top_src_node->next;
	top_src_node->next = *dst;
	*dst = top_src_node;
	if (pb_or_pa)
	{
		ft_putstr_fd(pb_or_pa, 1);
		ft_putstr_fd("\n", 1);
	}
}
