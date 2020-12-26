/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:43:11 by ahel-men          #+#    #+#             */
/*   Updated: 2019/04/16 17:00:20 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*tab;
	size_t			i;
	size_t			count;
	unsigned int	nb;

	i = 0;
	count = ft_intlen(n);
	tab = ft_strnew(count);
	if (!tab)
		return (NULL);
	if (n < 0 && (n *= -1))
		tab[i++] = '-';
	nb = n;
	while (count-- && nb / 10 != 0)
	{
		tab[count] = (nb % 10) + 48;
		nb /= 10;
	}
	tab[count] = nb + 48;
	return (tab);
}
