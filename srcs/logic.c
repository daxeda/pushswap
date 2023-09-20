/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeniaherzi <xeniaherzi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:25:44 by xeniaherzi        #+#    #+#             */
/*   Updated: 2023/09/20 08:29:27 by xeniaherzi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	two_args(int argc, const char **argv, t_data **stack)
{
	int		i;
	char	**tab;

	tab = NULL;
	if (argc == 2)
	{
		i = 0;
		tab = ft_split(argv[1], ' ');
		if (!tab || !tab[i])
			ft_error(NULL, NULL, -1, ERROR);
		while (tab[i])
			i++;
		while (--i >= 0)
			*stack = ft_add_node(*stack, ft_atoi(tab[i], *stack));
		i = -1;
		while (tab[++i])
			free(tab[i]);
		free(tab[i]);
		free(tab);
		ft_error(*stack, NULL, checkdup(*stack), ERROR);
	}
}

void	sortStack(t_data **stack_a, t_data **stack_b)
{
	t_data	*cp_a;
	int		nb_node;

	nb_node = 0;
	cp_a = *stack_a;
	fill_index(stack_a);
	if (checksorted(*stack_a) == 0)
	{
		ft_free_stack(*stack_a, NULL);
		exit(EXIT_SUCCESS);
	}
	while (cp_a)
	{
		cp_a = cp_a->next;
		nb_node++;
	}
	if (nb_node == 2 && (*stack_a)->value > (*stack_a)->next->value)
		swap_top_two("sa\n", stack_a);
	else if (nb_node == 3)
		sort_substack_three(stack_a);
	else if (nb_node > 3 && nb_node < 6)
		sort_substack_four_five(stack_a, stack_b);
	else if (nb_node > 5)
		radix_algo(stack_a, stack_b);
}

void	moveAndSort(t_data **s_a, t_data **s_b, int pos, int len_s_a)
{
	int	i;

	i = -1;
	if (pos <= len_s_a / 2)
		while (++i < pos)
			rotate_stack("ra\n", s_a);
	else if (pos > len_s_a / 2)
		while (++i < len_s_a - pos)
			reverse_rotate("rra\n", s_a);
	moveAtoB(s_a, s_b);
}
