/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_col_lin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 19:16:55 by jacher            #+#    #+#             */
/*   Updated: 2021/02/07 22:07:26 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		check_ext_col(char **map_tab)
{
	int	i;
	int	j;
	int col;
	int lin;

	j = 0;
	col = ft_strlen(map_tab[0]);
	while (j < col)
	{
		i = 0;
		while (map_tab[i] && (map_tab[i][j] == ' ' || map_tab[i][j] == 'x'))
		{
			map_tab[i][j] = 'x';//les espaces checkes deviennent des x
			i++;
		}
		if (map_tab[i] != NULL && map_tab[i][j] != '1')
			return (-1);
		else
			j++;
	}
	j = 0;
	lin = 0;
	while (map_tab[lin])
		lin++;
	while (j < col)
	{
		i = lin - 1;
		while (i >= 0 && (map_tab[i][j] == ' ' || map_tab[i][j] == 'x'))
		{
			map_tab[i][j] = 'x';//les espaces checkes deviennent des x
			i--;
		}
		if (i != -1 && map_tab[i][j] != '1')
			return (-1);
		else
			j++;
	}
	return (1);
}

int		check_ext_lin(char **map_tab)
{
	int	i;
	int	j;

	i = 0;
	while (map_tab[i] != NULL)
	{
		j = 0;
		while (map_tab[i][j] == ' ')
		{
			map_tab[i][j] = 'x';//les espaces checkes deviennent des x
			j++;
		}
		if (map_tab[i][j] != '\0' && map_tab[i][j] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (map_tab[i] != NULL)
	{
		j = ft_strlen(map_tab[0]) - 1;
		while (j >= 0 && map_tab[i][j] == ' ')
		{
			map_tab[i][j] = 'x';//les espaces checkes deviennent des x
			j--;
		}
		if (j != -1 && map_tab[i][j] != '1')
			return (-1);
		i++;
	}
	return (1);
}

int		check_lin(char **map_tab, int lin, int col)
{
	int i;
	int max;

	max = ft_strlen(map_tab[0]);
	i = col - 1;
	while (i >= 0 && map_tab[lin][i] != '1' && map_tab[lin][i] != ' ')
		i--;
	if (i == -1 || map_tab[lin][i] == ' ')
		return (-1);
	i = col + 1;
	while (i < max && map_tab[lin][i] != '1' && map_tab[lin][i] != ' ')
		i++;
	if (i == max || map_tab[lin][i] == ' ')
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
	while (i >= 0 && map_tab[i][col] != '1' && map_tab[i][col] != ' ')
		i--;
	if (i == -1 || map_tab[i][col] == ' ')
		return (-1);
	i = lin + 1;
	while (i < max && map_tab[i][col] != '1' && map_tab[i][col] != ' ')
		i++;
	if (i == max || map_tab[i][col] == ' ')
		return (-1);
	return (1);
}
