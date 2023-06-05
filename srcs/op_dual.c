/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_dual.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42Seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 20:39:08 by inchoi            #+#    #+#             */
/*   Updated: 2023/06/01 21:12:03 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	dual_plus(int ca, int cb, t_stack *stack_a, t_stack *stack_b)
{
	while (1)
	{
		if (ca == 0 || cb == 0)
			break ;
		rotate_twice(stack_a, stack_b);
		ca--;
		cb--;
	}
	if (ca > 0)
	{
		while (ca > 0)
		{
			rotate_a(stack_a, 1);
			ca--;
		}
	}
	else if (cb > 0)
	{
		while (cb > 0)
		{
			rotate_b(stack_b, 1);
			cb--;
		}
	}
}

static void	dual_minus(int ca, int cb, t_stack *stack_a, t_stack *stack_b)
{
	while (1)
	{
		if (ca == 0 || cb == 0)
			break ;
		rrotate_twice(stack_a, stack_b);
		ca++;
		cb++;
	}
	if (ca < 0)
	{
		while (ca < 0)
		{
			rrotate_a(stack_a, 1);
			ca++;
		}
	}
	else if (cb < 0)
	{
		while (cb < 0)
		{
			rrotate_b(stack_b, 1);
			cb++;
		}
	}
}

void	shift_dual(t_node *node, t_stack *stack_a, t_stack *stack_b)
{
	int	ca;
	int	cb;

	ca = node->cost_a;
	cb = node->cost_b;
	if (ca > 0 && cb > 0)
		dual_plus(ca, cb, stack_a, stack_b);
	else if (ca < 0 && cb < 0)
		dual_minus(ca, cb, stack_a, stack_b);
}
