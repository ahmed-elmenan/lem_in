/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_queue.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:23:12 by ahel-men          #+#    #+#             */
/*   Updated: 2020/10/27 14:14:34 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	ft_create_queue_node(t_qu *q)
{
	q->queue = (t_list_node *)ft_memalloc(sizeof(t_list_node));
	q->rear = q->queue;
	q->front = q->queue;
}

int		ft_enqueue(t_qu *q, int vertex)
{
	t_list_node *node;

	node = (t_list_node *)ft_memalloc(sizeof(t_list_node));
	node->dst = vertex;
	q->rear->next = node;
	q->rear = node;
	return (1);
}

void	ft_dequeue(t_qu *q)
{
	t_list_node *previous_front;

	previous_front = NULL;
	previous_front = q->front;
	q->front = q->front->next;
	if (previous_front)
	{
		free(previous_front);
		previous_front = NULL;
	}
}
