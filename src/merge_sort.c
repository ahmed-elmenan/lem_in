/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:15:04 by aybouras          #+#    #+#             */
/*   Updated: 2020/11/13 14:15:07 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
*** recursively merge two sorted list into another sorted list
*/

t_vertices	*join_list(t_parse *prs, t_vertices *right, t_vertices *left)
{
	t_vertices *new_head;

	new_head = NULL;
	if (!right)
		return (left);
	if (!left)
		return (right);
	if (ft_strcmp(right->vertex_name, left->vertex_name) < 0)
	{
		new_head = right;
		new_head->next = join_list(prs, right->next, left);
	}
	else
	{
		new_head = left;
		new_head->next = join_list(prs, right, left->next);
	}
	if (ft_strcmp(right->vertex_name, left->vertex_name) == 0)
		ft_rescue_memory(prs, ERROR);
	return (new_head);
}

/*
*** We use Floyd’s tortoise & hare algorithm for partitioning the linked list
*** into two halves. We declare a slow pointer and a fast pointer.
*** Slow pointer moves one step ahead where the fast pointer
*** moves two step at a time. Thus when the fast pointer reaches the end of
*** the list, the slow pointer is at the midway
*/

void		split_list(t_vertices *head, t_vertices **right, t_vertices **left)
{
	t_vertices *tortoise;
	t_vertices *hare;

	tortoise = head;
	hare = head->next;
	while (hare != NULL)
	{
		hare = hare->next;
		if (hare != NULL)
		{
			tortoise = tortoise->next;
			hare = hare->next;
		}
	}
	*right = head;
	*left = tortoise->next;
	tortoise->next = NULL;
}

/*
*** recursively sort the two lists
*/

void		merge_sort(t_parse *prs, t_vertices **original_head)
{
	t_vertices *head;
	t_vertices *right;
	t_vertices *left;

	head = *original_head;
	if (!head || head->next == NULL)
		return ;
	split_list(head, &right, &left);
	merge_sort(prs, &right);
	merge_sort(prs, &left);
	*original_head = join_list(prs, right, left);
	return ;
}
