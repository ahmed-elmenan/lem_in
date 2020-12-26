/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul_score.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 13:39:00 by ahel-men          #+#    #+#             */
/*   Updated: 2020/12/21 17:22:12 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	ft_free_groups(t_groups **group)
{
	t_groups	*tmp;
	t_groups	*lst;
	t_list_node	*path;
	t_list_node	*tmp2;

	lst = *group;
	while (lst)
	{
		path = lst->path_holder;
		while (path)
		{
			tmp2 = path->next;
			ft_strdel_int(&(path->path));
			ft_strdel_int(&(path->track));
			free(path);
			path = tmp2;
		}
		ft_strdel_int(&(lst->merged_paths));
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

void	ft_free_lst(t_list_node **lst)
{
	t_list_node *tmp;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

void	ft_free_vlst(t_vertices **lst)
{
	t_vertices *tmp;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		ft_strdel(&(*lst)->vertex_name);
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

void	ft_free_graph(t_graph *gr)
{
	int			v;
	t_list_node	*tmp;

	v = 0;
	if (gr)
	{
		if (gr->nb_v)
		{
			while (v < gr->nb_v)
			{
				tmp = gr->tab[v].list;
				ft_free_lst(&gr->tab[v].list);
				v++;
			}
			free(gr->tab);
		}
		free(gr);
	}
}

void	ft_rescue_memory(t_parse *prs, int flag)
{
	if (flag)
		ft_putstr("ERROR\n");
	ft_strdel(&prs->line);
	ft_strdel(&prs->the_rest);
	free_2d(prs->array_of_rooms, prs->total_vertices);
	ft_free_groups(&prs->store_regular_path);
	if (prs->rooms_lst)
		ft_free_vlst(&prs->rooms_lst);
	ft_free_graph(prs->graph);
	ft_strdel(&prs->end);
	ft_strdel(&prs->start);
	exit(0);
}
