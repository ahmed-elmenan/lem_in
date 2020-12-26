/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_graph.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:34:36 by ahel-men          #+#    #+#             */
/*   Updated: 2020/10/29 11:49:58 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_list_node	*ft_create_list_node(int dst)
{
	t_list_node		*node;

	node = (t_list_node *)malloc(sizeof(t_list_node));
	node->dst = dst;
	node->flow = 0;
	return (node);
}

t_graph		*ft_create_graph(int nb)
{
	t_graph			*gr;
	int				i;

	gr = (t_graph *)malloc(sizeof(t_graph));
	gr->nb_v = nb;
	gr->tab = (t_lst *)malloc(sizeof(t_lst) * nb);
	i = -1;
	while (++i < nb)
		gr->tab[i].list = NULL;
	return (gr);
}

void		ft_create_link(t_graph *gr, int src, int dest)
{
	t_list_node		*node2;

	node2 = ft_create_list_node(dest);
	node2->next = gr->tab[src].list;
	gr->tab[src].list = node2;
	node2 = ft_create_list_node(src);
	node2->next = gr->tab[dest].list;
	gr->tab[dest].list = node2;
}
