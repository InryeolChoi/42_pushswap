/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_AtoB.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42Seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:35:10 by inchoi            #+#    #+#             */
/*   Updated: 2023/05/29 17:37:34 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_number(int n, int *arr, int *p1, int *p2)
{
	if (n % 3 == 0)
	{
		(*p1) = arr[n / 3 - 1];
		(*p2) = arr[(n / 3) * 2 - 1];
	}
	else
	{
		(*p1) = arr[n / 3];
		if (n % 3 == 1)
			(*p2) = arr[(n / 3) * 2];
		else if (n % 3 == 2)
			(*p2) = arr[(n / 3) * 2 + 1];
	}
}

static void	find_pivot(int n, t_node *node, int *p1, int *p2)
{
	int	i;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * n);
	if (!arr)
		return ;
	i = 0;
	while (i < n)
	{
		arr[i++] = node->data;
		node = node->before;
	}
	quick_sort(arr, 0, n - 1);
	get_number(n, arr, p1, p2);
	free(arr);
}

static void	change_a(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int	i;
	int	num;

	i = 0;
	num = stack_a->count;
	while (i < num)
	{
		if (stack_a->rear->data < pivot)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a, 1);
		i++;
	}
}

void	move_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	p1;
	int	p2;

	if (stack_a->count > 6)
	{
		find_pivot(stack_a->count, stack_a->rear, &p1, &p2);
		change_a(stack_a, stack_b, p1);
		change_a(stack_a, stack_b, p2);
	}
	if (stack_a->count >= 3)
	{
		while (stack_a->count > 3)
			push_b(stack_a, stack_b);
	}
	undersize(stack_a);
}
