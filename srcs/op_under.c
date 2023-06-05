/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_under.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42Seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:41:33 by inchoi            #+#    #+#             */
/*   Updated: 2023/05/29 17:31:31 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_1(t_stack *stack, int d1, int d2, int d3)
{
	if (d1 > d2 && d2 > d3)
	{
		swap_a(stack, 1);
		rrotate_a(stack, 1);
	}
	else if (d1 < d2 && d2 > d3)
		rrotate_a(stack, 1);
	else if (d1 > d2 && d2 < d3)
		rotate_a(stack, 1);
}

static void	case_2(t_stack *stack, int d1, int d2, int d3)
{
	if (d1 < d2 && d2 > d3)
	{
		swap_a(stack, 1);
		rotate_a(stack, 1);
	}
	else
		swap_a(stack, 1);
}

static void	two_element(t_stack *stack)
{
	int	front;
	int	rear;

	front = stack->front->data;
	rear = stack->rear->data;
	if (front < rear)
		swap_a(stack, 1);
}

static void	three_element(t_stack *stack)
{
	int	d1;
	int	d2;
	int	d3;

	d1 = stack->rear->data;
	d2 = stack->rear->before->data;
	d3 = stack->front->data;
	if (d1 < d2 && d2 < d3)
		return ;
	else if (d1 > d3)
		case_1(stack, d1, d2, d3);
	else
		case_2(stack, d1, d2, d3);
}

void	undersize(t_stack *stack_a)
{
	if (stack_a->count == 2)
		two_element(stack_a);
	else if (stack_a->count == 3)
		three_element(stack_a);
}
