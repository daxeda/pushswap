/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeniaherzi <xeniaherzi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:24:38 by xeniaherzi        #+#    #+#             */
/*   Updated: 2023/09/20 08:29:38 by xeniaherzi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* pushes an element --> stack_b --> stack_a */
void	moveBtoA(t_data **stack_a, t_data **stack_b)
{
	t_data	*first_b;

	if (!stack_b)
		return ;
	first_b = *stack_b;
	*stack_b = (*stack_b)->next;
	first_b->next = *stack_a;
	*stack_a = first_b;
	ft_putstr_fd("moveBtoA\n", 1);
}
/* pushes an element --> stack_a --> stack_b */
void	moveAtoB(t_data **stack_a, t_data **stack_b)
{
	t_data	*first_a;

	if (!stack_a)
		return ;
	first_a = *stack_a;
	*stack_a = (*stack_a)->next;
	first_a->next = *stack_b;
	*stack_b = first_a;
	ft_putstr_fd("moveAtoB\n", 1);
}
