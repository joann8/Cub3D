/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_col_lin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 19:16:55 by jacher            #+#    #+#             */
/*   Updated: 2021/02/10 11:40:25 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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
	return (1);
}

int		check_ext_lin_2(char **map_tab)
{
	int	i;
	int	j;

	i = 0;
	while (map_tab[i] != NULL)
	{
		j = ft_strlen(map_tab[0]) - 1;
		while (j >= 0 && (map_tab[i][j] == ' ' || map_tab[i][j] == 'x'))
		{
			map_tab[i][j] = 'x';
			j--;
		}
		if (j != -1 && map_tab[i][j] != '1')
			return (-1);
		i++;
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
		while (map_tab[i][j] == ' ' || map_tab[i][j] == 'x')
		{
			map_tab[i][j] = 'x';
			j++;
		}
		if (map_tab[i][j] != '\0' && map_tab[i][j] != '1')
			return (-1);
		i++;
	}
	if (check_ext_lin_2(map_tab) == -1)
		return (-1);
	return (1);
}
