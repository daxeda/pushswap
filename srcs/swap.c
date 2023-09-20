/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_top_two.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeniaherzi <xeniaherzi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:25:32 by xeniaherzi        #+#    #+#             */
/*   Updated: 2023/09/19 08:30:19 by xeniaherzi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_top_two(const char *s, t_data **stack)
{
	t_data	*first;
	t_data	*second;
	t_data	*third;

	if (stack && *stack && (*stack)->next)
	{
		first = *stack;
		second = first->next;
		*stack = second;
		if (second->next)
			third = second->next;
		else
			third = NULL;
		first->next = third;
		second->next = first;
		ft_putstr_fd(s, 1);
	}
}

void	ss(t_data **stack_a, t_data **stack_b)
{
	swap_top_two(NULL, stack_a);
	swap_top_two(NULL, stack_b);
	ft_putstr_fd("ss\n", 1);
}
