/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:27:45 by stycho            #+#    #+#             */
/*   Updated: 2022/01/11 17:45:15 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*instruction;

	if (argc < 2)
		return (0);
	if (argc < 3)
		ft_perror_and_exit("Error\nYou must provide at least two integers\n");
	ft_get_stack_a(&stack_a, argv);
	instruction = "dummy";
	while (instruction)
	{
		instruction = get_next_line(0);
		ft_check_instruction(&stack_b, &stack_a, instruction);
		ft_apply_instruction(&stack_b, &stack_a, instruction);
	}
	if (stack_b == NULL && ft_is_sorted(stack_a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
