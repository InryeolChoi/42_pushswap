/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_final.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42Seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:35:02 by inchoi            #+#    #+#             */
/*   Updated: 2023/05/29 17:33:35 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_node *node)
{
	int	idx;
	int	ans;
	int	min;

	idx = 0;
	min = INT_MAX;
	while (node)
	{
		if (node->data < min)
		{
			min = node->data;
			ans = idx;
		}
		node = node->before;
		idx++;
	}
	return (ans);
}

static int	fix_idx(t_stack *stack_a, int idx)
{
	int	count;

	count = stack_a->count;
	if (idx <= count / 2)
		return (idx);
	else
		return (idx - count);
}

void	final_set(t_stack *stack_a)
{
	int		idx;
	t_node	*node;

	node = stack_a->rear;
	idx = find_min(node);
	idx = fix_idx(stack_a, idx);
	while (idx > 0)
	{
		rotate_a(stack_a, 1);
		idx--;
	}
	while (idx < 0)
	{
		rrotate_a(stack_a, 1);
		idx++;
	}
}
