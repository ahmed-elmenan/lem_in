/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:22:43 by ahel-men          #+#    #+#             */
/*   Updated: 2020/12/22 11:47:37 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_list_node		*ft_get_node(t_list_node *list, int vertex)
{
	t_list_node	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->dst == vertex)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void			ft_manage_flow(t_parse *prs)
{
	int			len;
	t_list_node	*tmp;
	t_list_node	*vertex;
	t_list_node	*vertex2;
	int			*path_v;

	path_v = prs->path;
	len = prs->path_verteces;
	while (--len > 0)
	{
		tmp = prs->graph->tab[path_v[len]].list;
		vertex = ft_get_node(tmp, path_v[len - 1]);
		vertex->flow++;
		tmp = prs->graph->tab[path_v[len - 1]].list;
		vertex2 = ft_get_node(tmp, path_v[len]);
		if (vertex2->flow)
		{
			vertex->flow = 0;
			vertex2->flow = 0;
			prs->is_intersection = TRUE;
		}
	}
}

int				free_bfs_memory(t_parse *prs, int *visited, t_qu *q)
{
	ft_free_lst(&q->front);
	ft_strdel_int(&prs->path);
	ft_strdel_int(&visited);
	return (1);
}

void			ft_bfs_init(t_parse *prs, int **visited, t_qu *q)
{
	*visited = (int *)ft_memalloc(sizeof(int) * prs->total_vertices);
	ft_int_tab_set(*visited, -1, prs->total_vertices);
	ft_create_queue_node(q);
	q->queue->dst = prs->start_index;
	q->queue->parent = prs->start_index;
}

int				ft_bfs(t_parse *prs, int flow)
{
	t_qu		q;
	int			*visited;
	t_list_node	*tmp;

	ft_bfs_init(prs, &visited, &q);
	while (visited[prs->end_index] == -1)
	{
		tmp = prs->graph->tab[q.front->dst].list;
		while (tmp)
		{
			if (visited[tmp->dst] == -1 && (flow == tmp->flow)
				&& ft_enqueue(&q, tmp->dst))
				q.rear->parent = q.front->dst;
			tmp = tmp->next;
		}
		if (visited[q.front->dst] == -1)
			visited[q.front->dst] = q.front->parent;
		ft_dequeue(&q);
		if (!q.front)
			break ;
	}
	if (!ft_manipulate_path(prs, &q, visited, flow))
		return (0);
	return (1);
}
