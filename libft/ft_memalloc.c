/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:15:50 by aybouras          #+#    #+#             */
/*   Updated: 2020/01/25 20:16:57 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *fresh_mem;

	fresh_mem = NULL;
	fresh_mem = (void *)malloc(size);
	if (fresh_mem == NULL)
		return (NULL);
	ft_bzero(fresh_mem, size);
	return (fresh_mem);
}
