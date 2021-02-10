/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rcf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:08:47 by jacher            #+#    #+#             */
/*   Updated: 2021/02/10 19:06:41 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		skip_space_comma(char *map_str, int *pos, int tour)
{
	int	i;
	int	mod;

	i = *pos;
	mod = 0;
	while (map_str[i] == ' ' || map_str[i] == ',')
	{
		if (map_str[i] == ',')
			mod++;
		i++;
	}
	if ((i == *pos) || (tour == 1 && mod != 0) || (tour == 2 && mod != 1)
		|| ft_isdigit(map_str[i]) == 0)
		return (-1);
	*pos = i;
	return (1);
}

int		data_r(char *map_str, t_map *map, int *position)
{
	int i;

	i = *position + 1;
	if (skip_space_comma(map_str, &i, 1) == -1)
		return (print_error_parsing(13));
	map->r_x = ft_atoi_cub(map_str + i, &i);
	if (skip_space_comma(map_str, &i, 1) == -1)
		return (print_error_parsing(13));
	map->r_y = ft_atoi_cub(map_str + i, &i);
	if (map->r_x > 0 && map->r_y > 0)
		map->r = 1;
	else
		return (print_error_parsing(13));
	*position = i;
	return (1);
}

int		data_f(char *map_str, t_map *map, int *position)
{
	int i;

	i = *position + 1;
	if (skip_space_comma(map_str, &i, 1) == -1)
		return (print_error_parsing(14));
	map->f_r = ft_atoi_cub(map_str + i, &i);
	if (skip_space_comma(map_str, &i, 2) == -1)
		return (print_error_parsing(14));
	map->f_g = ft_atoi_cub(map_str + i, &i);
	if (skip_space_comma(map_str, &i, 2) == -1)
		return (print_error_parsing(14));
	map->f_b = ft_atoi_cub(map_str + i, &i);
	if ((map->f_r >= 0 && map->f_r <= 255)
			&& (map->f_g >= 0 && map->f_g <= 255)
			&& (map->f_b >= 0 && map->f_b <= 255))
		map->f = 1;
	else
		return (print_error_parsing(14));
	*position = i;
	return (1);
}

int		data_c(char *map_str, t_map *map, int *position)
{
	int i;

	i = *position + 1;
	if (skip_space_comma(map_str, &i, 1) == -1)
		return (print_error_parsing(15));
	map->c_r = ft_atoi_cub(map_str + i, &i);
	if (skip_space_comma(map_str, &i, 2) == -1)
		return (print_error_parsing(15));
	map->c_g = ft_atoi_cub(map_str + i, &i);
	if (skip_space_comma(map_str, &i, 2) == -1)
		return (print_error_parsing(15));
	map->c_b = ft_atoi_cub(map_str + i, &i);
	if ((map->c_r >= 0 && map->c_r <= 255)
			&& (map->c_g >= 0 && map->c_g <= 255)
			&& (map->c_b >= 0 && map->c_b <= 255))
		map->c = 1;
	else
		return (print_error_parsing(15));
	*position = i;
	return (1);
}
