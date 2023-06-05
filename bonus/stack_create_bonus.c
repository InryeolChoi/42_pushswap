/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42Seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:35:17 by inchoi            #+#    #+#             */
/*   Updated: 2023/05/29 17:29:22 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	isempty(t_stack *stack)
{
	if (stack->count == 0)
		return (1);
	return (0);
}

t_stack	*create_stack(void)
{
	t_stack	*deque;

	deque = (t_stack *)malloc(sizeof(t_stack));
	if (!deque)
		return (NULL);
	deque->front = NULL;
	deque->rear = NULL;
	deque->count = 0;
	return (deque);
}

void	delete_stack(t_stack *stack)
{
	t_node	*curnode;
	t_node	*nextnode;

	curnode = stack->front;
	while (curnode)
	{
		nextnode = curnode->next;
		free(curnode);
		curnode = nextnode;
	}
	free(stack);
}

t_node	*create_node(int n)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->before = NULL;
	node->next = NULL;
	node->data = n;
	return (node);
}

void	delete_node(t_node *node)
{
	free(node);
}
