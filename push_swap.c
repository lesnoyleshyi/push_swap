/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:55:30 by stycho            #+#    #+#             */
/*   Updated: 2022/01/10 18:55:31 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 3)
		return (0);
	ft_get_stack_a(&stack_a, argv);
	ft_index_this_list(stack_a);
	if (ft_is_cir_sorted(stack_a))
	{
		ft_final_sort(&stack_a);
		ft_lstclear(&stack_a, free);
		return (0);
	}
	if (argc == 6)
		ft_sort_five(&stack_b, &stack_a);
	else
	{
		ft_presort(&stack_b, &stack_a);
		ft_little_cir_sort(&stack_a, "sa");
		ft_move_back_from_stack_b(&stack_b, &stack_a);
	}
	ft_final_sort(&stack_a);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
