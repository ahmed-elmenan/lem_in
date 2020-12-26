/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:13:37 by aybouras          #+#    #+#             */
/*   Updated: 2020/12/21 17:13:46 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		*ft_strdup_int(int *s1, int start, int size)
{
	int		i;
	int		*pt;

	if (!s1)
		return (0);
	if (!(pt = (int *)ft_memalloc(sizeof(int) * size)))
		return (0);
	i = 0;
	while (size--)
		pt[i++] = s1[start++];
	return (pt);
}
