/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_to_end_directly.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:37:57 by aybouras          #+#    #+#             */
/*   Updated: 2020/12/21 17:38:04 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	start_to_end_directly(t_parse *prs, char **tab, int lenght)
{
	int x;

	if ((!ft_strcmp(prs->start, tab[1]) && !ft_strcmp(prs->end, tab[2]))
			|| (!ft_strcmp(prs->end, tab[1]) && !ft_strcmp(prs->start, tab[2])))
	{
		x = 1;
		while (x <= prs->nbr_ants)
		{
			ft_putchar('L');
			ft_putnbr(x);
			ft_putchar('-');
			ft_putstr(prs->end);
			ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		free_2d(tab, lenght + 1);
		ft_rescue_memory(prs, 0);
		exit(0);
	}
}
