/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:56:13 by aybouras          #+#    #+#             */
/*   Updated: 2020/01/15 15:56:33 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	char		*joined;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(joined = ft_strnew(i)))
		return (NULL);
	ft_strcpy(joined, s1);
	ft_strcat(joined, s2);
	return (joined);
}
