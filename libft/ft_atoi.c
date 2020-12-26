/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:06:00 by aybouras          #+#    #+#             */
/*   Updated: 2020/01/25 20:16:48 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ascii_to_int(const char *str, int index)
{
	int	result;

	result = 0;
	while (ft_isdigit(str[index]))
	{
		result = result * 10 + (str[index] - '0');
		index++;
	}
	return (result);
}

int			ft_atoi(const char *str)
{
	int result;
	int sign;
	int index;

	result = 0;
	sign = 1;
	index = 0;
	while (ft_isspace(str[index]))
	{
		index++;
	}
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
	return ((result * sign));
}
