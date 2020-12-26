/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:20:47 by akhossan          #+#    #+#             */
/*   Updated: 2019/11/17 14:20:49 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ascii_to_int(const char *str, int index)
{
	long long	result;

	result = 0;
	while (ft_isdigit(str[index]))
	{
		result = result * 10 + (str[index] - '0');
		index++;
	}
	return (result);
}

long long int		ft_atoll(const char *str)
{
	long long	result;
	int			sign;
	int			index;

	result = 0;
	sign = 1;
	index = 0;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '-')
	{
		sign = -1;
		index++;
	}
	else if (str[index] == '+')
	{
		sign = 1;
		index++;
	}
	result = ascii_to_int(str, index);
	if (result > INT_MAX || result < 0)
		return (-1);
	return ((result * sign));
}
