/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeniaherzi <xeniaherzi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:25:54 by xeniaherzi        #+#    #+#             */
/*   Updated: 2023/09/20 08:29:41 by xeniaherzi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_data	*ft_add_node(t_data *node, int val)
{
	t_data	*tmp;

	tmp = malloc(sizeof(t_data));
	if (tmp)
	{
		tmp->value = val;
		tmp->next = node;
	}
	return (tmp);
}

void	fill_index(t_data **stack_a)
{
	t_data	*first;
	t_data	*cp_a;
	int		i;

	first = *stack_a;
	cp_a = *stack_a;

	while (*stack_a)
	{
		cp_a = first;
		i = 0;
		while (cp_a)
		{
			if ((*stack_a)->value > cp_a->value)
				i++;
			if ((*stack_a)->index != i)
				(*stack_a)->index = i;
			if (!cp_a->next)
				break ;
			cp_a = cp_a->next;
		}
		*stack_a = (*stack_a)->next;
	}
	*stack_a = first;
}

void	print_list(t_data *node)
{
	while (node)
	{
		printf("[%p][%d]\n", node, node->value);
		node = node->next;
		if (!node)
			printf("[%p]NULL\n", node);
	}
}

void ft_print_two_stack(t_data *stack_a, t_data *stack_b)
{
    printf("[STACK_A]\n");
    while (stack_a)
    {
        printf("[%p][%d][%d]\n", stack_a, stack_a->value, stack_a->index);
        stack_a = stack_a->next;
    }
    if (!stack_a)
        printf("[%p]NULL\n", stack_a);
    
    printf("[STACK_B]\n");
    while (stack_b)
    {
        printf("[%p][%d][%d]\n", stack_b, stack_b->value, stack_b->index);
        stack_b = stack_b->next;
    }
    if (!stack_b)
        printf("[%p]NULL\n", stack_b);
}
