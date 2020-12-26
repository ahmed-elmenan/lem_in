/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:48:48 by aybouras          #+#    #+#             */
/*   Updated: 2020/01/15 15:48:58 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*pt;
	size_t	size;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	pt = (char *)ft_memalloc(sizeof(char) * size + 1);
	if (pt == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		pt[i] = s1[i];
		i++;
	}
	pt[i] = '\0';
	return (pt);
}
