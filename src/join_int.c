/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:29:01 by aybouras          #+#    #+#             */
/*   Updated: 2020/12/21 17:29:21 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		*join_tab_int(int tab1[], int tab2[],
						int len1, int len2)
{
	int		i;
	int		*joined;
	int		len;

	len = len1 + len2;
	joined = (int *)ft_memalloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		if (i < len1)
			joined[i] = tab1[i];
		else
			joined[i] = tab2[i - len1];
		i++;
	}
	quick_sort(joined, 0, len - 1);
	return (joined);
}
