/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 10:13:28 by aybouras          #+#    #+#             */
/*   Updated: 2020/11/14 10:13:36 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	parse_chk(t_parse *prs, char c, int words_counter, int space_counter)
{
	if ((c == ' ' && (words_counter != 3 || space_counter != 2))
		|| (c == '-' && (words_counter != 2 || space_counter != 1)))
	{
		ft_rescue_memory(prs, ERROR);
	}
}

int		ft_word_count(t_parse *prs, char *str, char c)
{
	int words_counter;
	int i;
	int space_counter;

	i = 0;
	space_counter = 0;
	words_counter = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
		{
			i++;
			space_counter++;
		}
		while (str[i] != c && str[i] != '\0')
			i++;
		while (str[i] == c && str[i] != '\0')
		{
			i++;
			space_counter++;
		}
		words_counter++;
	}
	parse_chk(prs, c, words_counter, space_counter);
	return (words_counter);
}

int		ft_word_size(char *str, char c)
{
	int			i;
	static	int	call_counter = 0;

	i = 0;
	call_counter++;
	while (str[i] == c && str[i] != '\0')
		str++;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

/*
*** first index is reserved to store the arrays's lenght (nbr of words)
*** we'll need it for debuging
*/

char	**split(t_parse *prs, char *str, char c)
{
	int		word_count;
	int		words_stored;
	int		i;
	char	**words;
	char	*word;

	i = 0;
	words_stored = 1;
	word_count = ft_word_count(prs, str, c) + 1;
	words = (char **)malloc(sizeof(char *) * (word_count + 1));
	words[0] = ft_ltoa(word_count);
	while (words_stored < word_count)
	{
		word = (char *)malloc(sizeof(char) * (ft_word_size(str, c) + 1));
		while (str[0] == c && str[0] != '\0')
			str++;
		while (str[0] != c && str[0] != '\0')
			word[i++] = *str++;
		word[i] = '\0';
		words[words_stored++] = word;
		i = 0;
	}
	words[word_count] = 0;
	return (words);
}

char	**parse_line(t_parse *prs, char *str, char c)
{
	char	**tab;
	int		row;
	int		lenght;

	if (!str || str[0] == 'L')
		ft_rescue_memory(prs, ERROR);
	tab = split(prs, str, c);
	row = 1;
	lenght = (int)ft_atoll(tab[0]);
	if ((c == ' ' && (!is_number(tab[2]) || !is_number(tab[3]))))
	{
		free_2d(tab, lenght + 1);
		ft_rescue_memory(prs, ERROR);
	}
	return (tab);
}
