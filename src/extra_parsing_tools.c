/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_parsing_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:15:58 by aybouras          #+#    #+#             */
/*   Updated: 2020/12/21 17:16:20 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	get_edges(t_parse *prs)
{
	char	**tab;
	int		x;
	int		y;
	int		lenght;

	tab = parse_line(prs, prs->line, '-');
	lenght = (int)ft_atoll(tab[0]);
	start_to_end_directly(prs, tab, lenght);
	x = ft_binary_search(prs, prs->array_of_rooms, tab[1]);
	y = ft_binary_search(prs, prs->array_of_rooms, tab[2]);
	if (x < 0 || y < 0)
	{
		free_2d(tab, lenght + 1);
		ft_rescue_memory(prs, ERROR);
	}
	free_2d(tab, lenght + 1);
	ft_create_link(prs->graph, x, y);
}

char	*get_vertices(t_parse *prs, char *line)
{
	char	**array;
	char	*vertex;
	int		len;

	array = parse_line(prs, line, ' ');
	if (!array || !*array)
	{
		ft_strdel(&line);
		prs->line = ft_strdup("nothing");
		ft_rescue_memory(prs, ERROR);
	}
	if (array[1][0] >= '!' && array[1][0] <= 126)
		fill_lst(&prs->rooms_lst, array);
	prs->total_vertices++;
	len = (int)ft_atoll(array[0]);
	vertex = ft_strdup(array[1]);
	free_2d(array, len + 1);
	return (vertex);
}

void	store_start_end_index(t_parse *prs)
{
	prs->start_index = ft_binary_search(prs, prs->array_of_rooms, prs->start);
	prs->end_index = ft_binary_search(prs, prs->array_of_rooms, prs->end);
}

void	no_start_end_error(t_parse *prs)
{
	if (!prs->start_is_set || !prs->end_is_set)
		ft_rescue_memory(prs, ERROR);
}

void	isolated_start_end_error(t_parse *prs)
{
	if (!prs->graph->tab[prs->start_index].list
		|| !prs->graph->tab[prs->end_index].list)
		ft_rescue_memory(prs, ERROR);
}
