/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42Seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:08:30 by inchoi            #+#    #+#             */
/*   Updated: 2023/05/28 18:54:26 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	operate(t_stack *stack_a, t_stack *stack_b)
{
	int	total;

	total = stack_a->count;
	if (stack_a->count <= 3)
		undersize(stack_a);
	else
	{
		move_to_b(stack_a, stack_b);
		back_to_a(stack_a, stack_b);
		final_set(stack_a);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (check_av(ac, av) == 0)
		return (set_error());
	else if (check_av(ac, av) == 2)
		return (set_empty());
	stack_a = get_stack(ac, av);
	if (check_dup(stack_a) == 0)
		return (set_error());
	if (check_setup(stack_a) == 0)
		return (set_empty());
	stack_b = create_stack();
	if (!stack_b)
		return (0);
	operate(stack_a, stack_b);
	delete_stack(stack_a);
	delete_stack(stack_b);
	return (0);
}
