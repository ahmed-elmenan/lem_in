/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:31:42 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/03 18:03:57 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && *p1 == *p2)
	{
		if (*p1 == '\0')
			return (*p1 - *p2);
		p1++;
		p2++;
		i++;
	}
	return (*p1 - *p2);
}
