/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42Seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:24:30 by inchoi            #+#    #+#             */
/*   Updated: 2023/05/29 17:25:33 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack_a, int x)
{
	t_node	*node;

	if (x == 1)
		ft_putstr_fd("ra\n", 1);
	if (isempty(stack_a))
		return ;
	node = pop_rear(stack_a);
	push_front(stack_a, node);
}

void	rotate_b(t_stack *stack_b, int x)
{
	t_node	*node;

	if (x == 1)
		ft_putstr_fd("rb\n", 1);
	if (isempty(stack_b))
		return ;
	node = pop_rear(stack_b);
	push_front(stack_b, node);
}

void	rotate_twice(t_stack *stack_a, t_stack *stack_b)
{
	rotate_a(stack_a, 0);
	rotate_b(stack_b, 0);
	ft_putstr_fd("rr\n", 1);
}
