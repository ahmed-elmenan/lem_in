/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:49:31 by aybouras          #+#    #+#             */
/*   Updated: 2020/10/29 11:46:49 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	fill_lst(t_vertices **head, char **array)
{
	t_vertices	*new;

	new = NULL;
	if (!*head)
	{
		if (!(*head = (t_vertices *)ft_memalloc(sizeof(t_vertices))))
			return ;
		(*head)->vertex_name = ft_strdup(array[1]);
		(*head)->coord_x = ft_atoll(array[2]);
		(*head)->coord_y = ft_atoll(array[3]);
		(*head)->next = NULL;
	}
	else
	{
		if (!(new = (t_vertices *)ft_memalloc(sizeof(t_vertices))))
			return ;
		new->vertex_name = ft_strdup(array[1]);
		new->coord_x = ft_atoll(array[2]);
		new->coord_y = ft_atoll(array[3]);
		new->next = *head;
		*head = new;
	}
}
