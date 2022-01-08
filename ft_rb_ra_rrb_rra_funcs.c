/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_ra_rrb_rra_funcs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:56:09 by stycho            #+#    #+#             */
/*   Updated: 2022/01/08 20:56:10 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_list **stack_b);
void	ft_rrb(t_list **stack_b);
void	ft_ra(t_list **stack_a);
void	ft_rra(t_list **stack_a);

void	ft_rb(t_list **stack_b)
{
	t_list	*b;

	b = *stack_b;
	ft_putstr_fd("\nrb\n", 1);
}

void	ft_rrb(t_list **stack_b)
{
	t_list	*b;

	b = *stack_b;
	ft_putstr_fd("\nrrb\n", 1);
}

void	ft_ra(t_list **stack_a)
{
	t_list	*a;

	a = *stack_a;
	ft_putstr_fd("\nra\n", 1);
}

void	ft_rra(t_list **stack_a)
{
	t_list	*a;

	a = *stack_a;
	ft_putstr_fd("\nrra\n", 1);
}
