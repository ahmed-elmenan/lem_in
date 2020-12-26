/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 08:33:17 by aybouras          #+#    #+#             */
/*   Updated: 2020/12/22 11:54:21 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	get_start_vertex(t_parse *prs)
{
	int		ret;
	char	*ligne;

	if (ft_strlen(prs->line) == 7 && !ft_strncmp(prs->line, "##start", 7))
	{
		if (prs->start_is_set == FALSE)
		{
			while ((ret = get_next(0, &ligne, prs)) > 0 && ligne[0] == '#')
			{
				if (!ft_strncmp(ligne, "##start", 7))
				{
					ft_strdel(&ligne);
					ft_rescue_memory(prs, ERROR);
				}
				ft_strdel(&ligne);
			}
			ft_putendl(ligne);
			prs->start = get_vertices(prs, ligne);
			prs->start_is_set = TRUE;
			ft_strdel(&ligne);
		}
		else
			ft_rescue_memory(prs, ERROR);
	}
}

void	get_end_vertex(t_parse *prs)
{
	int		ret;
	char	*ligne;

	if (ft_strlen(prs->line) == 5 && !ft_strncmp(prs->line, "##end", 5))
	{
		if (prs->end_is_set == FALSE)
		{
			while ((ret = get_next(0, &ligne, prs)) > 0 && ligne[0] == '#')
			{
				if (!ft_strncmp(ligne, "##end", 5))
				{
					ft_strdel(&ligne);
					ft_rescue_memory(prs, ERROR);
				}
				ft_strdel(&ligne);
			}
			ft_putendl(ligne);
			prs->end = get_vertices(prs, ligne);
			prs->end_is_set = TRUE;
			ft_strdel(&ligne);
		}
		else
			ft_rescue_memory(prs, ERROR);
	}
}

int		get_ants(t_parse *prs)
{
	int ret;

	ret = get_next(0, &prs->line, prs);
	ft_putendl(prs->line);
	if (ret > 0 && prs->line[0] == '#' && prs->line[1] != '#')
	{
		ft_strdel(&prs->line);
		return (get_ants(prs));
	}
	else if (ret > 0 && is_number(prs->line)
			&& (prs->nbr_ants = ft_atoll(prs->line)) > 0)
	{
		ft_strdel(&prs->line);
		return (1);
	}
	ft_rescue_memory(prs, ERROR);
	return (0);
}

void	rooms(t_parse *prs)
{
	char	*array;

	while ((prs->ret = get_next(0, &prs->line, prs)) > 0)
	{
		ft_putendl(prs->line);
		if (ft_strstr(prs->line, "-"))
		{
			prs->line_tmp = ft_strdup(prs->line);
			ft_strdel(&prs->line);
			return ;
		}
		if (prs->line[0] == '#' && prs->line[1] == '#')
		{
			get_start_vertex(prs);
			get_end_vertex(prs);
		}
		else if (prs->line[0] == '#' && prs->line[1] != '#')
			ft_strdel(&prs->line);
		else
		{
			array = get_vertices(prs, prs->line);
			ft_strdel(&array);
		}
		ft_strdel(&prs->line);
	}
}

void	links(t_parse *prs)
{
	int ret;

	ret = 0;
	prs->line = ft_strdup(prs->line_tmp);
	ft_strdel(&prs->line_tmp);
	get_edges(prs);
	ft_strdel(&prs->line);
	while ((ret = get_next(0, &prs->line, prs)))
	{
		ft_putendl(prs->line);
		if (!ft_strncmp(prs->line, "##end", 5)
				|| !ft_strncmp(prs->line, "##start", 7))
			ft_rescue_memory(prs, ERROR);
		if (prs->line[0] != '#')
			get_edges(prs);
		ft_strdel(&prs->line);
	}
}
