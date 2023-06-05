/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42Seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:29:07 by inchoi            #+#    #+#             */
/*   Updated: 2023/05/28 18:35:26 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs_num(int cost)
{
	if (cost < 0)
		return (cost * (-1));
	return (cost);
}

static int	get_cost_total(t_node *node)
{
	int	cost_a;
	int	cost_b;

	cost_a = abs_num(node->cost_a);
	cost_b = abs_num(node->cost_b);
	return (cost_a + cost_b);
}

static long long	fix_num(int x)
{
	long long	tmp;

	tmp = (long long) x;
	return (tmp);
}

void	calculate(t_stack *stack_a, t_stack *stack_b)
{
	int		idx;
	int		cnt;
	int		count_a;
	int		count_b;
	t_node	*node;

	idx = 0;
	node = stack_b->rear;
	count_a = stack_a->count;
	count_b = stack_b->count;
	cnt = count_a + count_b;
	while (idx < count_b)
	{
		node->cost_b = get_cost_b(idx, count_b);
		node->cost_a = get_cost_a(stack_a, fix_num(node->data), 0);
		node->cost_total = get_cost_total(node);
		node = node->before;
		idx++;
	}
}
