/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_balance_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:16:50 by ahel-men          #+#    #+#             */
/*   Updated: 2020/10/27 13:28:36 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	ft_broadcast_rest(t_groups *group, t_list_node **paths,
	int res, int best_score_path_id)
{
	while (res)
	{
		*paths = group->path_holder;
		while (paths && (*paths)->path_id !=
			best_score_path_id + 1 && res)
		{
			(*paths)->path_capacity += 1;
			res--;
			if (!res)
				return ;
			*paths = (*paths)->next;
		}
	}
}

void	ft_balance_paths(t_parse *prs, t_groups *group,
	int best_score_path_id)
{
	t_list_node	*paths;
	t_balance	balance;

	balance.remained_total = 0;
	balance.cap_add = 0;
	balance.max_len = prs->small_score_path->path_verteces - 2;
	paths = group->path_holder;
	while (paths && paths->path_id != best_score_path_id + 1)
	{
		paths->remaining = balance.max_len - (paths->path_verteces - 2);
		balance.remained_total += paths->remaining;
		paths = paths->next;
	}
	balance.res = prs->nbr_ants - balance.remained_total;
	balance.balance = balance.res / best_score_path_id;
	paths = group->path_holder;
	while (paths && paths->path_id != best_score_path_id + 1)
	{
		paths->path_capacity = paths->remaining + balance.balance;
		balance.cap_add += paths->path_capacity;
		balance.res = prs->nbr_ants - balance.cap_add;
		paths = paths->next;
	}
	ft_broadcast_rest(group, &paths, balance.res, best_score_path_id);
}
