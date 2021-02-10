/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_lin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 19:16:55 by jacher            #+#    #+#             */
/*   Updated: 2021/02/10 18:43:30 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		check_empty_lin(char **map_tab, int beg, int end)
{
	int	i;
	int	j;

	i = 0;
	while (map_tab[i] != NULL)
	{
		j = 0;
		while (map_tab[i][j] == ' ' || map_tab[i][j] == 'x')
			j++;
		if (map_tab[i][j] == '\0')
		{
			i++;
			if (beg == 1)
				end = 1;
		}
		else
		{
			beg = 1;
			if (end == 1)
				return (-1);
			i++;
		}
	}
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
	if (check_empty_lin(map_tab, 0, 0) == -1)
		return (-1);
	return (1);
}

int		check_lin(char **map_tab, int lin, int col)
{
	int i;
	int max;

	max = ft_strlen(map_tab[0]);
	i = col - 1;
	while (i >= 0 && map_tab[lin][i] != '1' && map_tab[lin][i] != 'x')
		i--;
	if (i == -1 || map_tab[lin][i] == 'x')
		return (-1);
	i = col + 1;
	while (i < max && map_tab[lin][i] != '1' && map_tab[lin][i] != 'x')
		i++;
	if (i == max || map_tab[lin][i] == 'x')
		return (-1);
	return (1);
}
