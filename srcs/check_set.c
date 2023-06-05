/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42Seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:35:43 by inchoi            #+#    #+#             */
/*   Updated: 2023/05/28 17:37:23 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_result(int minus, int plus)
{
	if (plus != 0 && minus != 0)
		return (1);
	else if (plus != 0 && minus == 0)
		return (1);
	else if (plus == 0 && minus != 0)
		return (0);
	return (0);
}

int	check_setup(t_stack *stack, int x)
{
	long long	d1;
	long long	d2;
	int			plus;
	int			minus;
	t_node		*node;

	plus = 0;
	minus = 0;
	node = stack->rear;
	while (node->before != NULL)
	{
		d1 = (long long) node->data;
		d2 = (long long) node->before->data;
		if (d1 - d2 > 0)
			plus += 1;
		else
			minus += 1;
		node = node->before;
	}
	if (stack->count != x)
		return (0);
	return (set_result(minus, plus));
}
