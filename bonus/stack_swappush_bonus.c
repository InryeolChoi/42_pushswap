/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swappush.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42Seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:31:43 by inchoi            #+#    #+#             */
/*   Updated: 2023/05/29 17:22:46 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap_a(t_stack *stack_a, int x)
{
	t_node	*node1;
	t_node	*node2;

	if (x == 1)
		ft_putstr_fd("sa\n", 1);
	if (isempty(stack_a) || isone(stack_a))
		return ;
	node1 = pop_rear(stack_a);
	node2 = pop_rear(stack_a);
	push_rear(stack_a, node1);
	push_rear(stack_a, node2);
}

void	swap_b(t_stack *stack_b, int x)
{
	t_node	*node1;
	t_node	*node2;

	if (x == 1)
		ft_putstr_fd("sb\n", 1);
	if (isempty(stack_b) || isone(stack_b))
		return ;
	node1 = pop_rear(stack_b);
	node2 = pop_rear(stack_b);
	push_rear(stack_b, node1);
	push_rear(stack_b, node2);
}

void	swap_twice(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
}

void	push_a(t_stack *stack_a, t_stack *stack_b, int x)
{
	t_node	*node;

	if (x == 1)
		ft_putstr_fd("pa\n", 1);
	if (isempty(stack_b))
		return ;
	node = pop_rear(stack_b);
	push_rear(stack_a, node);
}

void	push_b(t_stack *stack_a, t_stack *stack_b, int x)
{
	t_node	*node;

	if (x == 1)
		ft_putstr_fd("pb\n", 1);
	if (isempty(stack_a))
		return ;
	node = pop_rear(stack_a);
	push_rear(stack_b, node);
}
