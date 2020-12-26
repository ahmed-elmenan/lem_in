/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 08:42:20 by aybouras          #+#    #+#             */
/*   Updated: 2020/12/22 11:08:40 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	print_farm(t_parse *prs, int i)
{
	ft_putchar('L');
	ft_putnbr(prs->pth->track[i]);
	ft_putchar('-');
	ft_putstr(prs->array_of_rooms[prs->pth->path[i]]);
	ft_putchar(' ');
}

void	initialize(t_parse *prs)
{
	prs->grp = prs->small_score_group ?
					prs->small_score_group : prs->store_regular_path;
	prs->best_score_path = prs->small_score_path
		? prs->small_score_path->path_id : prs->grp->last_ptr->path_id;
	ft_balance_paths(prs, prs->grp, prs->best_score_path);
	prs->pth = prs->grp->path_holder;
	while (prs->pth)
	{
		prs->pth->track = (int *)ft_memalloc(prs->pth->path_verteces
																* sizeof(int));
		if (prs->pth->path_id == 1)
			prs->pth->starting_ant = 1;
		if (prs->pth->next)
			prs->pth->next->starting_ant =
				prs->pth->starting_ant + prs->pth->path_capacity;
		prs->pth->waiting = prs->pth->starting_ant - 1;
		prs->pth = prs->pth->next;
	}
}

void	print_path(t_parse *prs)
{
	int i;

	i = -1;
	while (++i < prs->pth->path_verteces - 1)
	{
		if (prs->pth->track[i + 1] != 0)
		{
			prs->pth->track[i] = prs->pth->track[i + 1];
			prs->pth->track[i + 1] = 0;
			if (prs->pth->track[i] <= prs->nbr_ants && prs->pth->track[i]
				< prs->pth->starting_ant + prs->pth->path_capacity)
			{
				print_farm(prs, i);
				if (i == 0 && prs->pth->track[i] > 0)
					prs->pth->track[0] = -1;
			}
			if (i == 0 && prs->pth->track[i] == -1)
				prs->ants_reached_end++;
		}
		if (i + 2 == prs->pth->path_verteces - 1)
		{
			prs->pth->waiting++;
			prs->pth->track[prs->pth->path_verteces - 1] = prs->pth->waiting;
		}
	}
}

void	send_ants(t_parse *prs)
{
	initialize(prs);
	prs->ants_reached_end = 0;
	while (prs->ants_reached_end != prs->nbr_ants)
	{
		prs->pth = prs->grp->path_holder;
		while (prs->pth)
		{
			print_path(prs);
			prs->pth = prs->pth->next;
		}
		ft_putchar('\n');
	}
}
