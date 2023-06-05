/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42Seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:25:43 by inchoi            #+#    #+#             */
/*   Updated: 2023/05/29 17:26:56 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_a(t_stack *stack_a, int x)
{
	t_node	*node;

	if (x == 1)
		ft_putstr_fd("rra\n", 1);
	if (isempty(stack_a))
		return ;
	node = pop_front(stack_a);
	push_rear(stack_a, node);
}

void	rrotate_b(t_stack *stack_b, int x)
{
	t_node	*node;

	if (x == 1)
		ft_putstr_fd("rrb\n", 1);
	if (isempty(stack_b))
		return ;
	node = pop_front(stack_b);
	push_rear(stack_b, node);
}

void	rrotate_twice(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr_fd("rrr\n", 1);
	rrotate_a(stack_a, 0);
	rrotate_b(stack_b, 0);
}
