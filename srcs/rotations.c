/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeniaherzi <xeniaherzi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:24:54 by xeniaherzi        #+#    #+#             */
/*   Updated: 2023/09/19 08:23:26 by xeniaherzi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/*reverse operation on stack --> moves last to front */
void	reverse_rotate(const char *s, t_data **stack)
{
	t_data	*first;
	t_data	*b_last;
	t_data	*last;

	b_last = NULL;
	if (stack && *stack)
	{
		first = *stack;
		while ((*stack)->next)
		{
			if (!(*stack)->next->next && !b_last)
				b_last = *stack;
			*stack = (*stack)->next;
		}
		last = *stack;
		*stack = last;
		last->next = first;
		b_last->next = NULL; // Separate the last element from the rest of the stack.
		ft_putstr_fd(s, 1);
	}
}
//This function performs a double reverse rotation operation on two stacks.
// It calls reverse_rotate on both stack_a and stack_b.
void	rrr(t_data **stack_a, t_data **stack_b)
{
	reverse_rotate(NULL, stack_a);
	reverse_rotate(NULL, stack_b);
	ft_putstr_fd("rrr\n", 1);
}

void	rotate_stack(const char *s, t_data **stack)
{
	t_data	*first;
	t_data	*second;
	t_data	*last;

	last = NULL;
	if (stack && *stack)
	{
		first = *stack;
		second = first->next;
		while ((*stack)->next)
			*stack = (*stack)->next;
		last = *stack;
		last->next = first;
		*stack = second;
		first->next = NULL;
		ft_putstr_fd(s, 1);
	}
}

void	rr(t_data **stack_a, t_data **stack_b)
{
	rotate_stack(NULL, stack_a);
	rotate_stack(NULL, stack_b);
	ft_putstr_fd("rr\n", 1);
}
