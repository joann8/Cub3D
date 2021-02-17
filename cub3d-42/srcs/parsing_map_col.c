/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_col.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 19:16:55 by jacher            #+#    #+#             */
/*   Updated: 2021/02/10 18:42:35 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		check_empty_col(char **map_tab, int col, int beg, int end)
{
	int	i;
	int	j;

	j = 0;
	while (j < col)
	{
		i = 0;
		while (map_tab[i] && (map_tab[i][j] == ' ' || map_tab[i][j] == 'x'))
			i++;
		if (map_tab[i] == NULL)
		{
			j++;
			if (beg == 1)
				end = 1;
		}
		else
		{
			beg = 1;
			if (end == 1)
				return (-1);
			j++;
		}
	}
	return (1);
}

int		check_ext_col_2(char **map_tab)
{
	int	i;
	int	j;
	int col;
	int lin;

	col = ft_strlen(map_tab[0]);
	j = 0;
	lin = 0;
	while (map_tab[lin])
		lin++;
	while (j < col)
	{
		i = lin - 1;
		while (i >= 0 && (map_tab[i][j] == ' ' || map_tab[i][j] == 'x'))
		{
			map_tab[i][j] = 'x';
			i--;
		}
		if (i != -1 && map_tab[i][j] != '1')
			return (-1);
		else
			j++;
	}
	return (1);
}

int		check_ext_col(char **map_tab)
{
	int	i;
	int	j;
	int col;

	j = 0;
	col = ft_strlen(map_tab[0]);
	while (j < col)
	{
		i = 0;
		while (map_tab[i] && (map_tab[i][j] == ' ' || map_tab[i][j] == 'x'))
		{
			map_tab[i][j] = 'x';
			i++;
		}
		if (map_tab[i] != NULL && map_tab[i][j] != '1')
			return (-1);
		else
			j++;
	}
	if (check_ext_col_2(map_tab) == -1)
		return (-1);
	if (check_empty_col(map_tab, col, 0, 0) == -1)
		return (-1);
	return (1);
}

int		check_col(char **map_tab, int lin, int col)
{
	int i;
	int max;

	max = 0;
	while (map_tab[max] != NULL)
		max++;
	i = lin - 1;
	while (i >= 0 && map_tab[i][col] != '1' && map_tab[i][col] != 'x')
		i--;
	if (i == -1 || map_tab[i][col] == 'x')
		return (-1);
	i = lin + 1;
	while (i < max && map_tab[i][col] != '1' && map_tab[i][col] != 'x')
		i++;
	if (i == max || map_tab[i][col] == 'x')
		return (-1);
	return (1);
}
