/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:50:40 by aybouras          #+#    #+#             */
/*   Updated: 2020/12/21 17:51:00 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		partition(int tab[], int start, int end)
{
	int pivot;
	int partition_index;
	int i;

	pivot = tab[end];
	partition_index = start;
	i = start;
	while (i < end)
	{
		if (tab[i] <= pivot)
		{
			swap(&tab[partition_index], &tab[i]);
			partition_index++;
		}
		i++;
	}
	swap(&tab[partition_index], &tab[end]);
	return (partition_index);
}

void	quick_sort(int tab[], int start, int end)
{
	int partition_index;

	if (start < end)
	{
		partition_index = partition(tab, start, end);
		quick_sort(tab, start, partition_index - 1);
		quick_sort(tab, partition_index + 1, end);
	}
}
