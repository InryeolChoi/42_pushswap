/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42Seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:53:28 by inchoi            #+#    #+#             */
/*   Updated: 2023/05/28 18:53:56 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	check_box(char *str)
{
	int	check;

	if (*str == '+' || *str == '-')
		str++;
	check = 0;
	while (*str != '\0')
	{
		if (ft_isdigit(*str))
			str++;
		else
			return (0);
		check = 1;
	}
	if (check == 0)
		return (0);
	return (1);
}

static long long	ft_strtol(char *str)
{
	long long	sign;
	long long	number;

	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	number = 0;
	while (*str != '\0')
	{
		number *= 10;
		number += *str - '0';
		str++;
	}
	return (sign * number);
}

int	free_box(char **box)
{
	int	idx;

	idx = 0;
	while (box[idx] != 0)
		free(box[idx++]);
	free(box);
	return (0);
}

static int	check_num(char *str, int *count)
{
	char		**box;
	char		**box_cpy;
	long long	number;

	box = ft_split(str, ' ');
	box_cpy = box;
	if (!box || !(*box))
		return (free_box(box_cpy));
	while (*box != 0)
	{
		if (!check_box(*box))
			return (free_box(box_cpy));
		number = ft_strtol(*box);
		if (number > INT_MAX || number < INT_MIN)
			return (free_box(box_cpy));
		(*count)++;
		box++;
	}
	free_box(box_cpy);
	return (1);
}

int	check_av(int ac, char **av)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	if (ac <= 1)
		return (2);
	while (i < ac)
	{
		if (!check_num(av[i++], &count))
			return (0);
		count++;
	}
	if (ac <= 2 && ac == count)
		return (2);
	return (1);
}
