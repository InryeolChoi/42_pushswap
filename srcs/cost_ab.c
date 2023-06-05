/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42Seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:36:22 by inchoi            #+#    #+#             */
/*   Updated: 2023/05/28 18:35:33 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_cost_b(int idx, int count)
{
	if (idx <= count / 2)
		return (idx);
	else
		return (idx - count);
}

static int	other_case(t_stack *stackA)
{
	int		idx;
	int		max;
	int		ans;
	t_node	*node;

	idx = 1;
	max = INT_MIN;
	ans = 0;
	node = stackA->rear;
	while (node)
	{
		if (node->data > max)
		{
			max = node->data;
			ans = idx;
		}
		node = node->before;
		idx++;
	}
	return (ans);
}

static int	fix_cost_a(t_stack *stackA, int n)
{
	int	count;

	count = stackA->count;
	if (n <= count / 2)
		return (n);
	else
		return (n - count);
}

int	get_cost_a(t_stack *stack_a, long long x, int idx)
{
	long long	tmp;
	long long	min;
	int			cost_a;
	t_node		*node_a;

	min = LONG_LONG_MAX;
	node_a = stack_a->rear;
	while (node_a)
	{
		if (x < node_a->data)
		{
			tmp = (node_a->data) - x;
			if (tmp < min)
			{
				min = tmp;
				cost_a = idx;
			}
		}
		node_a = node_a->before;
		idx++;
	}
	if (min == LONG_LONG_MAX)
		cost_a = other_case(stack_a);
	return (fix_cost_a(stack_a, cost_a));
}
