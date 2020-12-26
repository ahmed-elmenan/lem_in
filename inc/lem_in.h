/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 09:23:30 by aybouras          #+#    #+#             */
/*   Updated: 2020/12/22 12:21:27 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define BUFF_SIZE 2
# define ERROR 1

# include "../libft/libft.h"
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef enum			e_boolean
{
	FALSE,
	TRUE,
}						t_boolean;

typedef struct			s_vertices
{
	char				*vertex_name;
	int					coord_x;
	int					coord_y;
	struct s_vertices	*next;
}						t_vertices;

typedef struct			s_list_node
{
	int					dst;
	int					flow;
	int					parent;
	int					*path;
	int					path_id;
	int					path_verteces;
	int					local_score;
	int					*track;
	int					remaining;
	int					waiting;
	int					path_capacity;
	int					starting_ant;
	struct s_list_node	*next;
}						t_list_node;

typedef struct			s_lst
{
	t_list_node			*list;
}						t_lst;

typedef struct			s_graph
{
	t_lst				*tab;
	int					nb_v;
}						t_graph;

typedef struct			s_groups
{
	t_list_node			*path_holder;
	t_list_node			*last_ptr;
	int					group_id;
	int					*merged_paths;
	int					merged_paths_length;
	int					total_verteces;
	int					nbr_paths;
	int					counter;
	int					len;
	struct s_groups		*next;
	struct s_groups		*next_gr;
}						t_groups;

typedef struct			s_parse
{
	t_graph				*graph;
	t_vertices			*rooms_lst;
	t_groups			*store_regular_path;
	t_groups			*reg_last_ptr;
	t_groups			*store_intersected_path;
	t_groups			*inter_last_ptr;
	t_groups			*small_score_group;
	t_list_node			*small_score_path;
	t_boolean			start_is_set;
	t_boolean			end_is_set;
	t_groups			*detected;
	t_groups			*last_gr;
	t_boolean			is_intersection;
	t_boolean			is_first_path;
	char				**array_of_rooms;
	char				*start;
	char				*end;
	char				*line;
	char				*line_tmp;
	char				*the_rest;
	int					*path;
	long				nbr_ants;
	int					start_index;
	int					end_index;
	int					nbr_paths;
	int					total_vertices;
	int					path_nbr_vertices;
	int					path_verteces;
	int					save_smallest_score;
	int					group_id;
	int					nbr1;
	int					nbr2;
	int					ret;
	int					best_score_path;
	t_groups			*grp;
	t_list_node			*pth;
	int					ants_reached_end;
}						t_parse;

typedef struct			s_qu
{
	t_list_node			*rear;
	t_list_node			*front;
	t_list_node			*queue;
}						t_qu;

typedef struct			s_balance
{
	int					balance;
	int					max_len;
	int					remained_total;
	int					res;
	int					cap_add;
}						t_balance;

t_vertices				*join_list(t_parse *prs, t_vertices *right,
						t_vertices *left);
t_graph					*ft_create_graph(int nb);
t_list_node				*ft_create_list_node(int dst);
t_list_node				*ft_get_node(t_list_node *list, int vertex);
int						*join_tab_int(int tab1[], int tab2[],
							int len1, int len2);
int						ft_binary_int_search(int *global_arr,
							int arr_size, int value_to_search);
int						ft_enqueue(t_qu *q, int vertex);
int						ft_binary_search(t_parse *prs, char **tab,
							char *vertex_name);
int						ft_bfs(t_parse *prs, int flow);
int						*ft_strdup_int(int *s1, int start, int size);
int						free_bfs_memory(t_parse *prs, int *visited, t_qu *q);
int						ft_strdel_int(int **as);
int						ft_strequ_int(int *s1, int *s2, int size);
int						ft_manipulate_path(t_parse *prs, t_qu *q,
							int *visited, int flow);
int						ft_queue_is_empty(t_qu *queue);
char					**parse_line(t_parse *prs, char *str, char c);
void					fill_lst(t_vertices **head, char **array);
void					merge_sort(t_parse *prs, t_vertices **original_head);
void					lst_2array(t_parse *prs);
void					ft_create_link(t_graph *gr, int src, int dest);
void					ft_create_queue_node(t_qu *q);
void					ft_dequeue(t_qu *q);
void					ft_free_graph(t_graph *gr);
void					ft_free_lst(t_list_node **lst);
void					ft_free_vlst(t_vertices **lst);
void					ft_manage_path(t_parse *prs);
void					ft_block_path(t_parse *prs, int *tab);
void					ft_store_path_in_group(t_parse *prs, int path_length,
							t_groups **store_path, t_groups **last_grp_ptr);
void					send_ants(t_parse *prs);
void					ft_balance_paths(t_parse *prs, t_groups *group,
							int best_score_path_id);
void					ft_rescue_memory(t_parse *prs, int flag);
void					ft_create_first_group(t_parse *prs,
							t_groups ***store_path, int path_length,
								t_groups **last_grp_ptr);
void					ft_store_in_same_group(t_parse *prs,
							t_groups **group_to_store, int path_length);
void					ft_create_new_group(t_parse *prs,
int						path_length, t_groups **last_grp_ptr);
void					ft_manage_flow(t_parse *prs);
void					ft_int_tab_set(int *tmp, int c, size_t len);
int						get_next(const int fd, char **line, t_parse *prs);
void					quick_sort(int tab[], int start, int end);
void					get_edges(t_parse *prs);
char					*get_vertices(t_parse *prs, char *line);
void					store_start_end_index(t_parse *prs);
void					no_start_end_error(t_parse *prs);
void					isolated_start_end_error(t_parse *prs);
void					get_start_vertex(t_parse *prs);
void					get_end_vertex(t_parse *prs);
int						get_ants(t_parse *prs);
void					rooms(t_parse *prs);
void					links(t_parse *prs);
void					start_to_end_directly(t_parse *prs,
						char **tab, int lenght);
#endif
