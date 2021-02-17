/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 19:16:55 by jacher            #+#    #+#             */
/*   Updated: 2021/02/10 11:31:06 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		check_around(char c, char **map_tab)
{
	int i;
	int j;

	i = 0;
	while (map_tab[i] != NULL)
	{
		j = 0;
		while (map_tab[i][j])
		{
			if (map_tab[i][j] == c)
			{
				if (check_lin(map_tab, i, j) == -1
						|| check_col(map_tab, i, j) == -1)
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	replace_last_spaces(char **map_tab)
{
	int i;
	int j;

	i = 0;
	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j])
		{
			if (map_tab[i][j] == ' ')
				map_tab[i][j] = 'x';
			j++;
		}
		i++;
	}
}

int		map_check_walls(char **map_tab)
{
	if (check_ext_lin(map_tab) == -1)
		return (print_error_parsing(7));
	if (check_ext_col(map_tab) == -1)
		return (print_error_parsing(7));
	if (check_around('0', map_tab) == -1
			|| check_around('2', map_tab) == -1)
		return (print_error_parsing(7));
	replace_last_spaces(map_tab);
	return (1);
}
