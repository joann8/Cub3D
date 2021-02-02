/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:23:06 by jacher            #+#    #+#             */
/*   Updated: 2021/02/02 21:33:38 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int			hit_a_wall(double x, double y, char **map_tab, t_map *map)
{
	int		i_lin;
	int		j_col;

	i_lin = y / map->tile_lin;
	j_col = x / map->tile_col;
	if (i_lin < map->map_lin && j_col < map->map_col
		&& map_tab[i_lin][j_col] == '0')
		return (0); //peut ton marcher sur un objet?
	else if (i_lin < map->map_lin && j_col < map->map_col
			&& map_tab[i_lin][j_col] == '1')
		return (1);
	else if (i_lin < map->map_lin && j_col < map->map_col
			&& map_tab[i_lin][j_col] == '2')
		return (2);
	else
		return (-1);
}

int			create_trgb(int t, int r, int g, int b)
{
	int color;

	color = t << 24;
	color |= r << 16;
	color |= g << 8;
	color |= b;
	return (color);
}

double		calculate_distance(double x1, double x2, double y1, double y2)
{
	double	result;

	result = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
	return (result);
}
