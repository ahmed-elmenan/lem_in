/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 00:08:52 by ahel-men          #+#    #+#             */
/*   Updated: 2019/04/14 00:09:57 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstlen(t_list *list)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = list;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
