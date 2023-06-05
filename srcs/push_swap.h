/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42Seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:04:11 by inchoi            #+#    #+#             */
/*   Updated: 2023/05/29 17:21:41 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif
# ifndef LONG_LONG_MAX
#  define LONG_LONG_MAX 9223372036854775807LL
# endif

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				data;
	int				cost_a;
	int				cost_b;
	int				cost_total;
	struct s_node	*before;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*front;
	t_node	*rear;
	int		count;
}	t_stack;

/* parsing */
int		free_box(char **box);
int		check_av(int ac, char **av);
int		check_dup(t_stack *stack);
int		check_setup(t_stack *stack);
int		isone(t_stack *stack);
int		isempty(t_stack *stack);
int		*make_arr(t_node *node, int cnt);

/* stack */
t_stack	*create_stack(void);
void	delete_stack(t_stack *stack);
t_node	*create_node(int n);
void	delete_node(t_node *node);

/* order */
void	push_front(t_stack *stack, t_node *node);
void	push_rear(t_stack *stack, t_node *node);
t_node	*pop_front(t_stack *stack);
t_node	*pop_rear(t_stack *stack);
void	swap_a(t_stack *stack_a, int x);
void	swap_b(t_stack *stack_b, int x);
void	swap_twice(t_stack *stack_a, t_stack *stack_b);
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);
void	rotate_a(t_stack *stack_a, int x);
void	rotate_b(t_stack *stack_b, int x);
void	rotate_twice(t_stack *stack_a, t_stack *stack_b);
void	rrotate_a(t_stack *stack_a, int x);
void	rrotate_b(t_stack *stack_b, int x);
void	rrotate_twice(t_stack *stack_a, t_stack *stack_b);

/* algorithm */
void	quick_sort(int *data, int left, int right);
void	move_to_b(t_stack *stack_a, t_stack *stack_b);
void	undersize(t_stack *stack_a);
void	back_to_a(t_stack *stack_a, t_stack *stack_b);
void	calculate(t_stack *stack_a, t_stack *stack_b);
int		get_cost_a(t_stack *stack_a, long long x, int idx);
int		get_cost_b(int idx, int count);
void	shift_dual(t_node *node, t_stack *stack_a, t_stack *stack_b);
void	final_set(t_stack *stack_a);

/* others */
t_stack	*get_stack(int ac, char **av);
int		set_error(void);
int		set_empty(void);
int		abs_num(int cost);

#endif
