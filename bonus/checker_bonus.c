/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42Seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:27:59 by inchoi            #+#    #+#             */
/*   Updated: 2023/05/30 18:31:27 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	set_answer(int ans)
{
	if (ans == 0)
		ft_putstr_fd("OK\n", 2);
	else if (ans == 1)
		ft_putstr_fd("KO\n", 1);
}

static void	r_with_rr(t_stack *stack_a, t_stack *stack_b, char *order)
{
	if (ft_strlen(order) == 3)
	{
		if (ft_strncmp(order, "ra", 2) == 0)
			rotate_a(stack_a, 2);
		else if (ft_strncmp(order, "rb", 2) == 0)
			rotate_b(stack_b, 2);
		else if (ft_strncmp(order, "rr", 2) == 0)
			rotate_twice(stack_a, stack_b, 2);
		else
			turn_off();
	}
	else if (ft_strlen(order) == 4)
	{
		if (ft_strncmp(order, "rra", 3) == 0)
			rrotate_a(stack_a, 2);
		else if (ft_strncmp(order, "rrb", 3) == 0)
			rrotate_b(stack_b, 2);
		else if (ft_strncmp(order, "rrr", 3) == 0)
			rrotate_twice(stack_a, stack_b, 2);
		else
			turn_off();
	}
	else
		turn_off();
}

static void	s_and_p(t_stack *stack_a, t_stack *stack_b, char *order)
{
	if (order[0] == 's')
	{
		if (ft_strncmp(order, "sa", 2) == 0)
			swap_a(stack_a, 2);
		else if (ft_strncmp(order, "sb", 2) == 0)
			swap_b(stack_b, 2);
		else if (ft_strncmp(order, "ss", 2) == 0)
			swap_twice(stack_a, stack_b);
		else
			turn_off();
	}
	else if (order[0] == 'p')
	{
		if (ft_strncmp(order, "pa", 2) == 0)
			push_a(stack_a, stack_b, 2);
		else if (ft_strncmp(order, "pb", 2) == 0)
			push_b(stack_a, stack_b, 2);
		else
			turn_off();
	}
	else
		turn_off();
}

static void	order_execute(t_stack *stack_a, t_stack *stack_b)
{
	int		x;
	int		ans;
	char	*order;

	x = stack_a->count;
	while (1)
	{
		order = get_next_line(0);
		if (!order)
			break ;
		if (order[0] == 'r')
			r_with_rr(stack_a, stack_b, order);
		else if (order[0] == 's' || order[0] == 'p')
			s_and_p(stack_a, stack_b, order);
		else
		{
			free(order);
			set_error();
			return ;
		}
		free(order);
	}
	ans = check_setup(stack_a, x);
	set_answer(ans);
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
	stack_b = create_stack();
	if (!stack_b)
		return (0);
	order_execute(stack_a, stack_b);
	delete_stack(stack_a);
	delete_stack(stack_b);
	return (0);
}
