/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeniaherzi <xeniaherzi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:24:27 by xeniaherzi        #+#    #+#             */
/*   Updated: 2023/09/20 08:29:22 by xeniaherzi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	sorted order of a linked list of integers */
int	checksorted(t_data *stack_a)
{
	t_data	*tmp;

	if (stack_a)
	{
		while ((stack_a)->next)
		{
			tmp = (stack_a)->next;
			while (tmp)
			{
				if ((stack_a)->value > tmp->value)
					return (-1);
				tmp = tmp->next;
			}
			stack_a = (stack_a)->next;
		}
	}
	else
		return (-1);
	return (0);
}
/*	check duplicates */
int	checkdup(t_data *node)
{
	t_data	*tmp;

	if (node)
	{
		while (node->next)
		{
			tmp = node->next;
			while (tmp)
			{
				if (node->value == tmp->value)
					return (-1);
				tmp = tmp->next;
			}
			node = node->next;
		}
	}
	return (0);
}
