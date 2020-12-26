/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:55:06 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/14 16:40:34 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	int		j;

	if (!s)
		return (NULL);
	sub = (char *)malloc(len + 1);
	if (start + len > ft_strlen(s) || sub == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (i < start + len)
	{
		sub[j] = s[i];
		j++;
		i++;
	}
	sub[j] = '\0';
	return (sub);
}
