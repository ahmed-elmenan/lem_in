/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:46:23 by aybouras          #+#    #+#             */
/*   Updated: 2020/12/22 11:29:46 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		free_2d(char **array, int len)
{
	int row;

	row = 0;
	if (array)
	{
		while (row < len)
		{
			ft_strdel(&array[row]);
			row++;
		}
		free(array);
		array = NULL;
	}
}
