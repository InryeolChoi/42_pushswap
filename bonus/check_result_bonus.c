/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42Seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:14:39 by inchoi            #+#    #+#             */
/*   Updated: 2023/05/30 15:14:40 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	set_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	set_empty(void)
{
	ft_putstr_fd("", 1);
	exit(1);
}

t_stack	*get_stack(int ac, char **av)
{
	int		i;
	char	**box;
	char	**box_cpy;
	t_stack	*stack;
	t_node	*node;

	i = 1;
	stack = create_stack();
	if (!stack)
		return (NULL);
	while (i < ac)
	{
		box = ft_split(av[i++], ' ');
		box_cpy = box;
		while (*box)
		{
			node = create_node(ft_atoi(*(box++)));
			push_front(stack, node);
		}
		free_box(box_cpy);
	}
	return (stack);
}
