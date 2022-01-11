/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:26:23 by stycho            #+#    #+#             */
/*   Updated: 2022/01/11 12:26:24 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_check_instruction(t_list **stack_b, t_list **stack_a, char *instr)
{
	if (ft_strncmp(instr, "rb\n", 3) == 0 || ft_strncmp(instr, "rrb\n", 4) == 0)
		return ;
	if (ft_strncmp(instr, "ra\n", 3) == 0 || ft_strncmp(instr, "rra\n", 4) == 0)
		return ;
	if (ft_strncmp(instr, "rr\n", 3) == 0 || ft_strncmp(instr, "rrr\n", 4) == 0)
		return ;
	if (ft_strncmp(instr, "pb\n", 3) == 0 || ft_strncmp(instr, "pa\n", 3) == 0)
		return ;
	if (ft_strncmp(instr, "sb\n", 3) == 0 || ft_strncmp(instr, "sa\n", 3) == 0)
		return ;
	if (ft_strncmp(instr, "ss\n", 3) == 0 )
		return ;
	ft_lstclear(stack_a, free);
	ft_lstclear(stack_b, free);
	ft_perror_and_exit("Error\nIncorrect instruction\n");
}

void	ft_apply_instruction(t_list **stack_b, t_list **stack_a, char *instr)
{
	if (ft_strncmp(instr, "rb\n", 3) == 0)
		ft_rotate(stack_b, NULL);
	if (ft_strncmp(instr, "ra\n", 3) == 0)
		ft_rotate(stack_a, NULL);
	if (ft_strncmp(instr, "rrb\n", 4) == 0)
		ft_rev_rotate(stack_b, NULL, 0);
	if (ft_strncmp(instr, "rra\n", 4) == 0)
		ft_rev_rotate(stack_a, NULL, 1);
	if (ft_strncmp(instr, "pb\n", 3) == 0)
		ft_push(stack_b, stack_a, "pb");
	if (ft_strncmp(instr, "pa\n", 3) == 0)
		ft_push(stack_a, stack_b, "pa");
	if (ft_strncmp(instr, "sb\n", 3) == 0)
		ft_swap(stack_b, "sb");
	if (ft_strncmp(instr, "sa\n", 3) == 0)
		ft_swap(stack_a, "sa");
	else
		ft_apply_double_instruction(stack_b, stack_a, instr);
}

void	ft_apply_double_instruction(t_list **st_b, t_list **st_a, char *instr)
{
	if (ft_strncmp(instr, "rr\n", 3) == 0)
	{
		ft_rotate(st_b, NULL);
		ft_rotate(st_a, NULL);
		return ;
	}
	if (ft_strncmp(instr, "rrr\n", 4) == 0)
	{
		ft_rev_rotate(st_b, NULL, 0);
		ft_rev_rotate(st_a, NULL, 1);
		return ;
	}
	if (ft_strncmp(instr, "ss\n", 3) == 0)
	{
		ft_swap(st_b, "sb");
		ft_swap(st_a, "sa");
	}
}

void	ft_print_list_content(t_list *lst)
{
	char	*cont;
	char	*score;

	ft_putstr_fd("val:\tscore:\n", 1);
	while (lst)
	{
		cont = ft_itoa(*((int *)(lst->content)));
		ft_putstr_fd(cont, 1);
		ft_putstr_fd("\t\t", 1);
		free(cont);
		score = ft_itoa(lst->score);
		ft_putstr_fd(score, 1);
		ft_putstr_fd("\t\t", 1);
		free(score);
		ft_putstr_fd("\n", 1);
		lst = lst->next;
	}
}

int 	ft_is_sorted(t_list *stack)
{
	if (stack)
		;
	return (1);
}
