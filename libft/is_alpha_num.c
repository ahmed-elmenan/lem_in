/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_alpha_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:18:54 by aybouras          #+#    #+#             */
/*   Updated: 2020/12/22 11:21:49 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		is_alnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z') || c == '_')
		return (1);
	return (0);
}

int				is_alpha_num(char *str)
{
	while (*str)
	{
		if (!is_alnum(*str))
			return (0);
		str++;
	}
	return (1);
}
