/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_sort_funcs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:25:29 by stycho            #+#    #+#             */
/*   Updated: 2022/01/09 16:25:30 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_final_sort(t_list **stack)
{
	int	min_val;
	int	ra_count;
	int	rra_count;

	min_val = ft_get_min_val(*stack);
	ra_count = ft_get_rb_cost(min_val, *stack);
	rra_count = ft_get_rrb_cost(min_val, *stack);
	if (ra_count <= rra_count)
	{
		while (ra_count--)
		{
			ft_rotate(stack, "ra");
			ft_putstr_fd("real\n", 1);
		}
	}
	else
	{
		while (rra_count--)
		{
			ft_rev_rotate(stack, "rra", 1);
			ft_putstr_fd("real\n", 1);
		}
	}
}
