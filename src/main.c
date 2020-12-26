/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 08:33:17 by aybouras          #+#    #+#             */
/*   Updated: 2020/12/21 17:08:03 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		main(void)
{
	t_parse prs;

	ft_memset((void *)&prs, 0, sizeof(t_parse));
	prs.start_is_set = FALSE;
	prs.end_is_set = FALSE;
	prs.is_intersection = FALSE;
	prs.group_id = 1;
	get_ants(&prs);
	rooms(&prs);
	no_start_end_error(&prs);
	merge_sort(&prs, &prs.rooms_lst);
	lst_2array(&prs);
	prs.graph = ft_create_graph(prs.total_vertices);
	links(&prs);
	store_start_end_index(&prs);
	isolated_start_end_error(&prs);
	ft_manage_path(&prs);
	ft_putchar('\n');
	send_ants(&prs);
	ft_rescue_memory(&prs, 0);
	return (0);
}
