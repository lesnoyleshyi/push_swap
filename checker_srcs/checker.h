/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_srcs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:49:10 by stycho            #+#    #+#             */
/*   Updated: 2022/01/11 12:49:11 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../push_swap.h"
# include "get_next_line.h"

void	ft_check_instruction(t_list **stack_b, t_list **stack_a, char *instr);
void	ft_apply_instruction(t_list **stack_b, t_list **stack_a, char *instr);
void	ft_apply_double_instruction(t_list **st_b, t_list **st_a, char *instr);
int 	ft_is_sorted(t_list *stack);

#endif