/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeniaherzi <xeniaherzi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:25:21 by xeniaherzi        #+#    #+#             */
/*   Updated: 2023/09/20 08:24:12 by xeniaherzi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_substack_three(t_data **stack_a)
{
	t_data	*f;
	t_data	*s;
	t_data	*t;

	f = *stack_a;
	s = f->next;
	t = s->next;
	if (f->value < s->value && s->value < t->value && s->value < t->value)
		return ;
	else if (f->value < s->value && f->value < t->value && s->value > t->value)
	{
		reverse_rotate("rra\n", stack_a);
		swap_top_two("sa\n", stack_a);
	}
	else if (f->value > s->value && f->value < t->value && s->value < t->value)
		swap_top_two("sa\n", stack_a);
	else if (f->value < s->value && f->value > t->value && s->value > t->value)
		reverse_rotate("rra\n", stack_a);
	else if (f->value > s->value && f->value > t->value && s->value < t->value)
		rotate_stack("ra\n", stack_a);
	else if (f->value > s->value && f->value > t->value && s->value > t->value)
	{
		rotate_stack("ra\n", stack_a);
		swap_top_two("sa\n", stack_a);
	}
}

void	sort_substack_four_five(t_data **stack_a, t_data **stack_b)
{
	int	len_stack_a;
	int	pos_i_min;
	int	pos_i_max;

	len_stack_a = ft_len_stack(*stack_a);
	pos_i_min = find_min(stack_a);
	moveAndSort(stack_a, stack_b, pos_i_min, len_stack_a);
	len_stack_a = ft_len_stack(*stack_a);
	pos_i_max = find_max(stack_a);
	moveAndSort(stack_a, stack_b, pos_i_max, len_stack_a);
	len_stack_a = ft_len_stack(*stack_a);
	if (len_stack_a == 2 && (*stack_a)->index > (*stack_a)->next->index)
		swap_top_two("sa\n", stack_a);
	else if (len_stack_a == 3)
		sort_substack_three(stack_a);
	moveBtoA(stack_a, stack_b);
	rotate_stack("ra\n", stack_a);
	moveBtoA(stack_a, stack_b);
}

void	radix_algo(t_data **stack_a, t_data **stack_b)
{
	t_data	*num;
	int		len;
	int		max_bits;
	int		i;
	int		j;

	len = ft_len_stack(*stack_a);
	max_bits = 0;
	while ((len - 1) >> max_bits != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < len)
		{
			num = *stack_a;
			if (((num->index >> i) & 1) == 1)
				rotate_stack("ra\n", stack_a);
			else
				moveAtoB(stack_a, stack_b);
		}
		while (*stack_b)
			moveBtoA(stack_a, stack_b);
	}
}
