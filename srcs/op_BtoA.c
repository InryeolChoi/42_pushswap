/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_BtoA.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42Seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:12:33 by inchoi            #+#    #+#             */
/*   Updated: 2023/05/28 18:50:59 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_cheap(t_stack *stack_b)
{
	int		min;
	int		ans;
	t_node	*node;

	node = stack_b->rear;
	min = INT_MAX;
	while (node)
	{
		if (node->cost_total < min)
		{
			min = node->cost_total;
			ans = node->data;
		}
		node = node->before;
	}
	return (ans);
}

static t_node	*cheap_node(t_stack *stack_b)
{
	int		idx;
	int		min_data;
	t_node	*node;

	idx = 0;
	node = stack_b->rear;
	min_data = find_cheap(stack_b);
	while (node)
	{
		if (node->data == min_data)
			break ;
		node = node->before;
		idx++;
	}
	return (node);
}

static void	shift_b(t_stack *stack_b, t_node *node)
{
	int	idx;

	idx = 0;
	if (node->cost_b > 0)
	{
		while (idx < node->cost_b)
		{
			rotate_b(stack_b, 1);
			idx++;
		}
	}
	else if (node->cost_b < 0)
	{
		while (idx > node->cost_b)
		{
			rrotate_b(stack_b, 1);
			idx--;
		}
	}
}

static void	shift_a(t_stack *stack_a, t_node *node)
{
	int	idx;

	idx = 0;
	if (node->cost_a > 0)
	{
		while (idx < node->cost_a)
		{
			rotate_a(stack_a, 1);
			idx++;
		}
	}
	else if (node->cost_a < 0)
	{
		while (idx > node->cost_a)
		{
			rrotate_a(stack_a, 1);
			idx--;
		}
	}
}

void	back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	while (!isempty(stack_b))
	{
		calculate(stack_a, stack_b);
		node = cheap_node(stack_b);
		if (node->cost_a * node->cost_b > 0)
			shift_dual(node, stack_a, stack_b);
		else
		{
			shift_b(stack_b, node);
			shift_a(stack_a, node);
		}
		push_a(stack_a, stack_b);
	}
}
