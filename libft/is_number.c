/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:32:53 by aybouras          #+#    #+#             */
/*   Updated: 2020/10/24 13:38:10 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** MIN = -2147483648 MAX = 2147483647
*/

int		is_number(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-')
		return (0);
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
