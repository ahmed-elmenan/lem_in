/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:25:48 by ahel-men          #+#    #+#             */
/*   Updated: 2020/10/27 14:13:27 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	ft_block_path(t_parse *prs, int *tab)
{
	int			len;
	t_list_node	*tmp;
	t_list_node	*vertex;
	int			*path_v;

	path_v = tab;
	len = prs->path_verteces;
	while (--len > 0)
	{
		tmp = prs->graph->tab[path_v[len]].list;
		vertex = ft_get_node(tmp, path_v[len - 1]);
		vertex->flow = -1;
	}
}

int		ft_strequ_int(int *s1, int *s2, int size)
{
	if (!s1 && !s2)
		return (1);
	if (s1 && s2)
		while (size >= 0)
		{
			if (!size)
				return (1);
			if (*s1 != *s2)
				break ;
			s1++;
			s2++;
			size--;
		}
	return (0);
}

int		ft_strdel_int(int **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
	return (1);
}

void	ft_manage_path(t_parse *prs)
{
	int x;

	x = 1;
	while (x)
		x = ft_bfs(prs, 0);
	x = 1;
	while (x)
		x = ft_bfs(prs, 1);
	if (prs->reg_last_ptr || prs->store_intersected_path)
		prs->reg_last_ptr->next = prs->store_intersected_path;
	else
	{
		ft_putstr("no solution\n");
		ft_rescue_memory(prs, ERROR);
	}
}
