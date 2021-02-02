/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_diag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 19:16:55 by jacher            #+#    #+#             */
/*   Updated: 2021/02/02 21:47:55 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		check_diag1(char **map_tab, int lin, int col)
{
	int i;
	int j;

	i = lin - 1;
	j = col - 1;
	while (i >= 0 && j >= 0 && map_tab[i][j] != '1' && map_tab[i][j] != ' ')
	{
		i--;
		j--;
	}
	if (i == -1 || j == -1 || map_tab[i][j] == ' ')
		return (-1);
	return (1);
}

int		check_diag2(char **map_tab, int lin, int col)
{
	int i;
	int j;
	int max_col;

	max_col = ft_strlen(map_tab[0]);
	i = lin - 1;
	j = col + 1;
	while (i >= 0 && j < max_col && map_tab[i][j] != '1'
			&& map_tab[i][j] != ' ')
	{
		i--;
		j++;
	}
	if (i == -1 || j == max_col || map_tab[i][j] == ' ')
		return (-1);
	return (1);
}

int		check_diag3(char **map_tab, int lin, int col)
{
	int i;
	int j;
	int max_lin;

	max_lin = 0;
	while (map_tab[max_lin] != NULL)
		max_lin++;
	i = lin + 1;
	j = col - 1;
	while (i < max_lin && j >= 0 && map_tab[i][j] != '1'
			&& map_tab[i][j] != ' ')
	{
		i++;
		j--;
	}
	if (i == max_lin || j == -1 || map_tab[i][j] == ' ')
		return (-1);
	return (1);
}

int		check_diag4(char **map_tab, int lin, int col)
{
	int i;
	int j;
	int max_lin;
	int max_col;

	max_col = ft_strlen(map_tab[0]);
	max_lin = 0;
	while (map_tab[max_lin] != NULL)
		max_lin++;
	i = lin + 1;
	j = col + 1;
	while (i < max_lin && j < max_col && map_tab[i][j] != '1'
			&& map_tab[i][j] != ' ')
	{
		i++;
		j++;
	}
	if (i == max_lin || j == max_col || map_tab[i][j] == ' ')
		return (-1);
	return (1);
}
