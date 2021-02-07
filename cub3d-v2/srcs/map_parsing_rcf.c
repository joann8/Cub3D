/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_rcf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:08:47 by jacher            #+#    #+#             */
/*   Updated: 2021/02/07 21:29:57 by jacher           ###   ########.fr       */
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
		return (print_error_parsing(13));
	*pos = i;
	return (1);
}

int		data_r(char *map_str, t_map *map, int *position)
{
	int i;

	i = *position + 1;
	if (skip_space_comma(map_str, &i, 1) == -1)
		return (-1);
	map->r_x_i = ft_atoi_cub(map_str + i, &i); // a verifier
	if (skip_space_comma(map_str, &i, 1) == -1)
		return (-1);
	map->r_y_i = ft_atoi_cub(map_str + i, &i); // a verifier
	if (map->r_x_i > 0 && map->r_y_i > 0)
	{
		map->r_x = map->r_x_i;
		map->r_y = map->r_y_i;
		//if (map->r_x_i > 1920)// valeur a verifier
		//	map->r_x = 1920;
		//if (map->r_y_i > 1080)// valeur a verifier
		//	map->r_y = 1080;
		map->r = 1;
	}
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
		return (-1);
	map->f_r = ft_atoi_cub(map_str + i, &i); // a verifier
	if (skip_space_comma(map_str, &i, 2) == -1)
		return (-1);
	map->f_g = ft_atoi_cub(map_str + i, &i); // a verifier
	if (skip_space_comma(map_str, &i, 2) == -1)
		return (-1);
	map->f_b = ft_atoi_cub(map_str + i, &i); // a verifier
	if ((map->f_r >= 0 && map->f_r <= 255)
			&& (map->f_g >= 0 && map->f_g <= 255)
			&& (map->f_b >= 0 && map->f_b <= 255))
		map->f = 1;
	else
		return (print_error_parsing(13));
	*position = i;
	return (1);
}

int		data_c(char *map_str, t_map *map, int *position)
{
	int i;

	i = *position + 1;
	if (skip_space_comma(map_str, &i, 1) == -1)
		return (-1);
	map->c_r = ft_atoi_cub(map_str + i, &i); // a verifier
	if (skip_space_comma(map_str, &i, 2) == -1)
		return (-1);
	map->c_g = ft_atoi_cub(map_str + i, &i); // a verifier
	if (skip_space_comma(map_str, &i, 2) == -1)
		return (-1);
	map->c_b = ft_atoi_cub(map_str + i, &i); // a verifier
	if ((map->c_r >= 0 && map->c_r <= 255)
			&& (map->c_g >= 0 && map->c_g <= 255)
			&& (map->c_b >= 0 && map->c_b <= 255))
		map->c = 1;
	else
		return (print_error_parsing(13));
	*position = i;
	return (1);
}
