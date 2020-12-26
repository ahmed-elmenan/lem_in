/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:40:39 by ahel-men          #+#    #+#             */
/*   Updated: 2020/10/29 12:02:13 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		ft_vertex_search(t_groups *groups, int *path, int *res,
		int path_length)
{
	int			i;

	i = -1;
	while (++i < path_length)
	{
		*res = ft_binary_int_search(groups->merged_paths,
				groups->merged_paths_length, path[i]);
		if (*res >= 0)
			break ;
	}
}

t_groups	*ft_detect_path_group(t_groups *store_path, int *path,
		int path_length)
{
	t_groups	*groups;
	t_list_node	*paths;
	int			res;

	groups = store_path;
	while (groups)
	{
		res = -2;
		paths = groups->path_holder;
		while (paths)
		{
			ft_vertex_search(groups, path, &res, path_length);
			if (res >= 0)
				break ;
			paths = paths->next;
		}
		if (res < 0)
			return (groups);
		groups = groups->next;
	}
	return (NULL);
}

void		ft_store_path_in_group(t_parse *prs, int path_length,
		t_groups **store_path, t_groups **last_grp_ptr)
{
	t_groups	*group_to_store;

	if (!*store_path)
	{
		ft_create_first_group(prs, &store_path, path_length,
				last_grp_ptr);
		return ;
	}
	group_to_store = NULL;
	group_to_store = ft_detect_path_group(*store_path, prs->path, path_length);
	if (group_to_store)
		ft_store_in_same_group(prs, &group_to_store, path_length);
	else
		ft_create_new_group(prs, path_length,
			last_grp_ptr);
}
