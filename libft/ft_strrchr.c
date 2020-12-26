/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:03:40 by aybouras          #+#    #+#             */
/*   Updated: 2020/01/15 16:03:47 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				size;

	size = ft_strlen(s);
	i = size;
	while (i >= 0)
	{
		if (s[i] != (char)c)
			i--;
		else
			return ((char *)(s + i));
	}
	return (0);
}
