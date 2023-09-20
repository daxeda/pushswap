/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeniaherzi <xeniaherzi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:25:49 by xeniaherzi        #+#    #+#             */
/*   Updated: 2023/09/20 08:29:30 by xeniaherzi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, const char **argv)
{
	t_data	*stack_a;
	t_data	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		two_args(argc, argv, &stack_a);
		sortStack(&stack_a, &stack_b);
	}
	else
	{
		while (--argc >= 1)
			stack_a = ft_add_node(stack_a, ft_atoi(argv[argc], stack_a));
		ft_error(stack_a, stack_b, checkdup(stack_a), ERROR);
		sortStack(&stack_a, &stack_b);
	}
	ft_free_stack(stack_a, NULL);
	return (0);
}
