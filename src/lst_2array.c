/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_2array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:24:11 by ahel-men          #+#    #+#             */
/*   Updated: 2020/10/27 14:25:16 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	lst_2array(t_parse *prs)
{
	int			size;
	int			index;
	t_vertices	*tmp;

	size = prs->total_vertices;
	tmp = prs->rooms_lst;
	prs->array_of_rooms = (char **)ft_memalloc(sizeof(char *) * size + 1);
	index = -1;
	while (tmp)
	{
		prs->array_of_rooms[++index] = ft_strdup(tmp->vertex_name);
		tmp = tmp->next;
	}
}
