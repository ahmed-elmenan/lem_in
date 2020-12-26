/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_groups.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:31:25 by aybouras          #+#    #+#             */
/*   Updated: 2020/12/21 17:36:55 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	ft_save_samllest_score(t_parse *prs, t_groups *groups,
	t_list_node *paths)
{
	prs->small_score_group = groups;
	prs->small_score_path = paths;
	prs->save_smallest_score = paths->local_score;
}

void	ft_create_first_group(t_parse *prs, t_groups ***store_path,
	int path_length, t_groups **last_grp_ptr)
{
	t_groups	*groups;
	t_list_node	*paths;

	**store_path = (t_groups *)ft_memalloc(sizeof(t_groups));
	groups = **store_path;
	groups->group_id = prs->group_id;
	groups->next = NULL;
	groups->path_holder = (t_list_node *)ft_memalloc(sizeof(t_list_node));
	paths = groups->path_holder;
	paths->next = NULL;
	paths->path_verteces = path_length;
	paths->path = ft_strdup_int(prs->path, 0, path_length);
	groups->merged_paths = ft_strdup_int(prs->path, 1, path_length - 2);
	groups->nbr_paths = 1;
	paths->path_id = 1;
	groups->merged_paths_length = path_length - 2;
	groups->total_verteces = path_length;
	paths->local_score = prs->nbr_ants + paths->path_verteces - 2;
	groups->last_ptr = paths;
	quick_sort(groups->merged_paths, 0, groups->merged_paths_length - 1);
	(*last_grp_ptr) = groups;
	if (!prs->save_smallest_score
		|| paths->local_score < prs->save_smallest_score)
		ft_save_samllest_score(prs, groups, paths);
}

void	ft_store_in_same_group(t_parse *prs, t_groups **group_to_store,
			int path_length)
{
	t_list_node	*new_path;
	int			*sv;
	int			len;

	new_path = (t_list_node *)ft_memalloc(sizeof(t_list_node));
	new_path->path = ft_strdup_int(prs->path, 0, path_length);
	new_path->path_verteces = path_length;
	(*group_to_store)->nbr_paths++;
	new_path->path_id = (*group_to_store)->nbr_paths;
	(*group_to_store)->last_ptr->next = new_path;
	len = (*group_to_store)->merged_paths_length;
	sv = (*group_to_store)->merged_paths;
	(*group_to_store)->merged_paths = join_tab_int(prs->path + 1,
		(*group_to_store)->merged_paths, path_length - 2, len);
	ft_strdel_int(&sv);
	(*group_to_store)->merged_paths_length = len + path_length - 2;
	(*group_to_store)->last_ptr = new_path;
	(*group_to_store)->total_verteces += path_length;
	prs->nbr1 = prs->nbr_ants + (*group_to_store)->total_verteces - 2 *
		(*group_to_store)->nbr_paths;
	prs->nbr2 = (*group_to_store)->nbr_paths;
	new_path->local_score = (prs->nbr1 % prs->nbr2 == 0)
						? prs->nbr1 / prs->nbr2 : (prs->nbr1 / prs->nbr2) + 1;
	if (new_path->local_score < prs->save_smallest_score)
		ft_save_samllest_score(prs, *group_to_store, new_path);
}

void	ft_create_new_group(t_parse *prs,
	int path_length, t_groups **last_grp_ptr)
{
	t_groups	*groups;
	t_list_node	*paths;

	groups = (t_groups *)ft_memalloc(sizeof(t_groups));
	groups->group_id = prs->group_id++;
	(*last_grp_ptr)->next = groups;
	(*last_grp_ptr) = groups;
	(*last_grp_ptr)->path_holder =
		(t_list_node *)ft_memalloc(sizeof(t_list_node));
	paths = (*last_grp_ptr)->path_holder;
	paths->next = NULL;
	paths->path_verteces = path_length;
	paths->path = ft_strdup_int(prs->path, 0, path_length);
	groups->merged_paths = ft_strdup_int(prs->path, 1, path_length - 2);
	groups->nbr_paths = 1;
	paths->path_id = 1;
	groups->last_ptr = paths;
	groups->total_verteces = path_length;
	paths->local_score = prs->nbr_ants + paths->path_verteces - 2;
	groups->merged_paths_length = path_length - 2;
	quick_sort(groups->merged_paths, 0, groups->merged_paths_length - 1);
	if (paths->local_score < prs->save_smallest_score)
		ft_save_samllest_score(prs, groups, paths);
}
