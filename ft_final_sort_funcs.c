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
//	char	*deb_min;
//	char	*deb_ra;
//	char	*deb_rra;
//
//	ft_putstr_fd("Inside final sort\n", 1);

	min_val = ft_get_min_val(*stack);
	ra_count = ft_get_rb_cost(min_val, *stack);
	rra_count = ft_get_rrb_cost(min_val, *stack);

//	deb_min = ft_itoa(min_val);
//	deb_ra = ft_itoa(ra_count);
//	deb_rra = ft_itoa(rra_count);
//
//	ft_putstr_fd("Min_val\tra\trra\n", 1);
//	ft_putstr_fd(deb_min, 1);
//	ft_putstr_fd("\t\t", 1);
//	ft_putstr_fd(deb_ra, 1);
//	ft_putstr_fd("\t", 1);
//	ft_putstr_fd(deb_rra, 1);
//	ft_putstr_fd("\n", 1);

	if (ra_count <= rra_count)
	{
		while (ra_count--)
			ft_rotate(stack, "ra");
	}
	else
	{
		while (rra_count--)
			ft_rev_rotate(stack, "rra", 1);
	}
}