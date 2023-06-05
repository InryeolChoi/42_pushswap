/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42Seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:35:23 by inchoi            #+#    #+#             */
/*   Updated: 2023/05/29 17:27:37 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	isone(t_stack *stack)
{
	if (stack->count == 1)
		return (1);
	return (0);
}

void	push_front(t_stack *stack, t_node *node)
{
	if (isempty(stack))
	{
		node->before = NULL;
		node->next = NULL;
		stack->front = node;
		stack->rear = node;
	}
	else
	{
		node->next = stack->front;
		stack->front->before = node;
		stack->front = node;
	}
	stack->count++;
}

void	push_rear(t_stack *stack, t_node *node)
{
	if (isempty(stack))
	{
		node->before = NULL;
		node->next = NULL;
		stack->front = node;
		stack->rear = node;
	}
	else
	{
		node->before = stack->rear;
		stack->rear->next = node;
		stack->rear = node;
	}
	stack->count++;
}

t_node	*pop_front(t_stack *stack)
{
	t_node	*node;

	if (isempty(stack))
		return (NULL);
	node = stack->front;
	if (stack->count == 1)
	{
		stack->front = NULL;
		stack->rear = NULL;
	}
	else
	{
		stack->front = node->next;
		stack->front->before = NULL;
	}
	node->before = NULL;
	node->next = NULL;
	stack->count--;
	return (node);
}

t_node	*pop_rear(t_stack *stack)
{
	t_node	*node;

	if (isempty(stack))
		return (NULL);
	node = stack->rear;
	if (stack->count == 1)
	{
		stack->front = NULL;
		stack->rear = NULL;
	}
	else
	{
		stack->rear = node->before;
		stack->rear->next = NULL;
	}
	node->before = NULL;
	node->next = NULL;
	stack->count--;
	return (node);
}
