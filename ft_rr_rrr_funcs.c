/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr_rrr_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:00:30 by stycho            #+#    #+#             */
/*   Updated: 2022/01/08 21:00:32 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_b, NULL);
	ft_rotate(stack_a, NULL);
	ft_putstr_fd("rr\n", 1);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rev_rotate(stack_b, NULL, 0);
	ft_rev_rotate(stack_a, NULL, 1);
	ft_putstr_fd("rrr\n", 1);
}

int	ft_get_rr_rrr_possible_count(int rb, int ra)
{
	int	rr_count;

	rr_count = 0;
	while (ra > 0 && rb > 0)
	{
		rr_count++;
		ra--;
		rb--;
	}
	return (rr_count);
}
