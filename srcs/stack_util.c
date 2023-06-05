/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42Seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:58:21 by inchoi            #+#    #+#             */
/*   Updated: 2023/05/29 17:24:19 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition(int arr[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] < pivot)
			swap(&arr[i++], &arr[j]);
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quick_sort(int *data, int left, int right)
{
	int	index;

	if (left < right)
	{
		index = partition(data, left, right);
		quick_sort(data, left, index - 1);
		quick_sort(data, index + 1, right);
	}
}

int	*make_arr(t_node *node, int cnt)
{
	int		i;
	int		*arr;

	arr = (int *)malloc(sizeof(int) * cnt);
	if (!arr)
		return (0);
	i = 0;
	while (i < cnt)
	{
		arr[i++] = node->data;
		node = node->next;
	}
	return (arr);
}
