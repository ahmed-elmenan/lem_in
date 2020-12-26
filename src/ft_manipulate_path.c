/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manipulate_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:40:15 by ahel-men          #+#    #+#             */
/*   Updated: 2020/10/29 12:00:43 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	ft_follow_parent(t_parse *prs, int *visited, int *i, int *y)
{
	while (visited[*i] != prs->start_index)
	{
		prs->path[(*y)++] = visited[*i];
		*i = visited[*i];
	}
}

int		ft_get_path(t_parse *prs, int *visited, int flow)
{
	int	i;
	int	y;

	i = prs->end_index;
	y = 0;
	if (visited[prs->end_index] == -1)
		return (0);
	prs->nbr_paths++;
	prs->path = (int *)ft_memalloc(sizeof(int) * prs->total_vertices);
	prs->path[y++] = i;
	ft_follow_parent(prs, visited, &i, &y);
	prs->path[y] = visited[i];
	prs->path_verteces = ++y;
	if (!flow)
		ft_store_path_in_group(prs, prs->path_verteces,
			&prs->store_regular_path, &prs->reg_last_ptr);
	else if (flow && prs->is_intersection)
		ft_store_path_in_group(prs, prs->path_verteces,
			&prs->store_intersected_path, &prs->inter_last_ptr);
	if (flow)
		ft_block_path(prs, prs->path);
	return (1);
}

void	ft_int_tab_set(int *tmp, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		tmp[i] = c;
		i++;
	}
}

int		ft_manipulate_path(t_parse *prs, t_qu *q, int *visited, int flow)
{
	if (!(ft_get_path(prs, visited, flow)) && free_bfs_memory(prs, visited, q))
		return (0);
	if (!flow)
		ft_manage_flow(prs);
	free_bfs_memory(prs, visited, q);
	return (1);
}
