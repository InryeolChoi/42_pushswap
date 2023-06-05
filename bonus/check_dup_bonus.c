/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42Seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:55:21 by inchoi            #+#    #+#             */
/*   Updated: 2023/05/26 20:09:15 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	check_union(int *arr, int max)
{
	int	i;
	int	n;

	n = 1;
	while (n < max)
	{
		i = 0;
		while (i < n)
		{
			if (arr[i] == arr[n])
				return (0);
			i++;
		}
		n++;
	}
	return (1);
}

int	check_dup(t_stack *stack)
{
	int		i;
	int		count;
	int		*arr;
	t_node	*node;

	count = stack->count;
	node = stack->front;
	arr = (int *)malloc(sizeof(int) * count);
	if (!arr)
		return (0);
	i = 0;
	while (i < stack->count)
	{
		arr[i++] = node->data;
		node = node->next;
	}
	if (check_union(arr, count) == 0)
	{
		free(arr);
		return (0);
	}
	free(arr);
	return (1);
}
