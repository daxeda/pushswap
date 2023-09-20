/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeniaherzi <xeniaherzi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:26:15 by xeniaherzi        #+#    #+#             */
/*   Updated: 2023/09/20 08:25:56 by xeniaherzi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

# define ERR_ARG "Invalid number of arguments !\n"
# define ERROR "Error\n"

typedef struct s_data
{
	int				value;
	int				index;
	struct s_data	*next;
}	t_data;

int		checkdup(t_data *node);
int		checksorted(t_data *stack_a);
void	ft_putstr_fd(const char *s, int fd);
int		ft_atoi(const char *str, t_data *node);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
void 	fill_index(t_data **stack_a);
t_data	*ft_add_node(t_data *node, int val);
void	print_list(t_data *node);
void	ft_print_two_stack(t_data *stack_a, t_data *stack_b);
void	moveBtoA(t_data **stack_a, t_data **stack_b);
void	moveAtoB(t_data **stack_a, t_data **stack_b);
int		find_min(t_data **stack);
void	ft_error(t_data *stack_a, t_data *stack_b, int res, const char *error);
int		ft_len_stack(t_data *stack);
void	ft_free_stack(t_data *stack_a, t_data *stack_b);
int		find_max(t_data **stack);
void	ss(t_data **stack_a, t_data **stack_b);
void	swap_top_two(const char *s, t_data **stack);
void	radix_algo(t_data **stack_a, t_data **stack_b);
void	sort_substack_four_five(t_data **stack_a, t_data **stack_b);
void	sortStack(t_data **stack_a, t_data **stack_b);
void	sort_substack_three(t_data **stack_a);
void	rrr(t_data **stack_a, t_data **stack_b);
void	reverse_rotate(const char *s, t_data **stack);
void	rotate_stack(const char *s, t_data **stack);
void	rr(t_data **stack_a, t_data **stack_b);
void	moveAndSort(t_data **s_a, t_data **s_b, int pos, int len_s_a);
void	sortStack(t_data **stack_a, t_data **stack_b);
void	two_args(int argc, const char **argv, t_data **stack);
int		checkdup(t_data *node);
int		checksorted(t_data *stack_a);

#endif