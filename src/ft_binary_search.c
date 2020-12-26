/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:38:09 by ahel-men          #+#    #+#             */
/*   Updated: 2020/10/27 14:01:43 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int	ft_binary_search(t_parse *prs, char **tab, char *vertex_name)
{
	int	start;
	int	end;
	int	mid;
	int	res;

	start = 0;
	end = prs->total_vertices - 1;
	mid = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		res = ft_strcmp(vertex_name, tab[mid]);
		if (!res)
			return (mid);
		else if (res < 0)
			end = mid - 1;
		else if (res > 0)
			start = mid + 1;
	}
	return (-1);
}

int	ft_binary_int_search(int *global_arr, int arr_size, int value_to_search)
{
	int start;
	int end;
	int mid;
	int res;

	start = 0;
	end = arr_size - 1;
	mid = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		res = value_to_search - global_arr[mid];
		if (!res)
			return (mid);
		else if (res < 0)
			end = mid - 1;
		else if (res > 0)
			start = mid + 1;
	}
	return (-1);
}
