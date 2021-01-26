/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:23:06 by jacher            #+#    #+#             */
/*   Updated: 2021/01/26 17:07:31 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		hit_a_wall(double x, double y, char **map_tab, t_map *map)
{
	int	i_lin;
	int j_col;
	
	i_lin = y / map->tile_lin;
	j_col = x / map->tile_col;
	if (i_lin < map->map_lin && j_col < map->map_col
			&& map_tab[i_lin][j_col] == '0') 
		return (0); //peut ton marcher sur un objet?
	else if (i_lin < map->map_lin && j_col < map->map_col
			&& map_tab[i_lin][j_col] == '1')
		return (1);
	else
		return (-1);
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}
