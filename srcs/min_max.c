/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeniaherzi <xeniaherzi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:00:07 by xeniaherzi        #+#    #+#             */
/*   Updated: 2023/09/20 08:29:34 by xeniaherzi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_min(t_data **stack)
{
	t_data	*first;
	int		count;

	first = *stack;
	count = 0;
	while (*stack)
	{
		if ((*stack)->index == 0)
			break ;
		count++;
		*stack = (*stack)->next;
	}
	*stack = first;
	return (count);
}

int	find_max(t_data **stack)
{
	t_data	*first;
	int		max_index;
	int		count;

	first = *stack;
	max_index = ft_len_stack(*stack);
	count = 0;
	while (*stack)
	{
		if ((*stack)->index == max_index)
			break ;
		count++;
		*stack = (*stack)->next;
	}
	*stack = first;
	return (count);
}
