/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:35:04 by akhossan          #+#    #+#             */
/*   Updated: 2019/11/17 20:59:33 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_length(long long nb)
{
	size_t	i;

	i = 1;
	while (nb / 10 != 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

char		*ft_ltoa(long long n)
{
	int					is_neg;
	char				*number;
	int					digits;
	unsigned long long	nbr;

	is_neg = (n < 0 ? 1 : 0);
	digits = nb_length(n);
	if (!(number = ft_strnew(digits + is_neg)))
		return (NULL);
	if (is_neg)
	{
		nbr = n * -1;
		number[0] = '-';
	}
	else
		nbr = n;
	while (digits > 0)
	{
		number[digits + is_neg - 1] = (nbr % 10) + '0';
		digits--;
		nbr /= 10;
	}
	return (number);
}
