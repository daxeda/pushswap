/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeniaherzi <xeniaherzi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:25:59 by xeniaherzi        #+#    #+#             */
/*   Updated: 2023/09/19 11:03:42 by xeniaherzi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_stack(t_data *stack_a, t_data *stack_b)
{
	t_data	*tmp;

	while (stack_a)
	{
		tmp = stack_a;
		stack_a = tmp->next;
		free(tmp);
	}
	while (stack_b)
	{
		tmp = stack_b;
		stack_b = tmp->next;
		free(tmp);
	}
}

void	ft_error(t_data *stack_a, t_data *stack_b, int res, const char *error)
{
	if (res < 0)
	{
		ft_free_stack(stack_a, stack_b);
		write(2, error, ft_strlen(error));
		exit(EXIT_FAILURE);
	}
}

int	ft_len_stack(t_data *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
