/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_divers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:14:08 by jacher            #+#    #+#             */
/*   Updated: 2021/02/07 18:28:44 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int				ft_atoi_cub(const char *str, int *pos)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	*pos = *pos + i;
	return (res);
}

void			ft_free_map(char **map_tab, int j)
{
	int i;

	i = 0;
	while (i < j && map_tab[i])
	{
		free(map_tab[i]);
		i++;
	}
	free(map_tab); // pas sure
}

int				define_tile_size(t_map *map)
{
	map->tile_col = map->r_x / map->map_col;
	map->tile_lin = map->r_y / map->map_lin;
	if (map->tile_col > map->tile_lin)
		map->tile_min = map->tile_lin;
	else
		map->tile_min = map->tile_col;
	map->tile_col = map->tile_min; // A CHANGER
	map->tile_lin = map->tile_min; // A CHANGER
	return (1);
}
