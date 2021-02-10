/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:08:47 by jacher            #+#    #+#             */
/*   Updated: 2021/02/10 11:26:26 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		data_no(char *map_str, t_map *map, int *position)
{
	int i;
	int	count;

	i = *position + 2;
	count = skip_space_folder(map_str, &i);
	if (count == -1)
		return (-1);
	map->no_path = malloc(sizeof(char) * (count + 1));
	if (map->no_path == NULL)
		return (print_error_parsing(10));
	ft_strlcpy(map->no_path, &(map_str[i]), count + 1);
	if (check_path_ext(map->no_path) == -1
			|| check_path_open(map->no_path) == -1)
		return (print_error_parsing(12));
	map->no = 1;
	*position = i + count;
	return (1);
}

int		data_so(char *map_str, t_map *map, int *position)
{
	int i;
	int	count;

	i = *position + 2;
	count = skip_space_folder(map_str, &i);
	if (count == -1)
		return (-1);
	map->so_path = malloc(sizeof(char) * (count + 1));
	if (map->so_path == NULL)
		return (print_error_parsing(10));
	ft_strlcpy(map->so_path, map_str + i, count + 1);
	if (check_path_ext(map->so_path) == -1
			|| check_path_open(map->so_path) == -1)
		return (print_error_parsing(12));
	map->so = 1;
	*position = i + count;
	return (1);
}

int		data_ea(char *map_str, t_map *map, int *position)
{
	int i;
	int	count;

	i = *position + 2;
	count = skip_space_folder(map_str, &i);
	if (count == -1)
		return (-1);
	map->ea_path = malloc(sizeof(char) * (count + 1));
	if (map->ea_path == NULL)
		return (print_error_parsing(10));
	ft_strlcpy(map->ea_path, map_str + i, count + 1);
	if (check_path_ext(map->ea_path) == -1
			|| check_path_open(map->ea_path) == -1)
		return (print_error_parsing(12));
	map->ea = 1;
	*position = i + count;
	return (1);
}

int		data_we(char *map_str, t_map *map, int *position)
{
	int i;
	int	count;

	i = *position + 2;
	count = skip_space_folder(map_str, &i);
	if (count == -1)
		return (-1);
	map->we_path = malloc(sizeof(char) * (count + 1));
	if (map->we_path == NULL)
		return (print_error_parsing(10));
	ft_strlcpy(map->we_path, map_str + i, count + 1);
	if (check_path_ext(map->we_path) == -1
		|| check_path_open(map->we_path) == -1)
		return (print_error_parsing(12));
	map->we = 1;
	*position = i + count;
	return (1);
}

int		data_s(char *map_str, t_map *map, int *position)
{
	int i;
	int	count;

	i = *position + 1;
	count = skip_space_folder(map_str, &i);
	if (count == -1)
		return (-1);
	map->s_path = malloc(sizeof(char) * (count + 1));
	if (map->s_path == NULL)
		return (print_error_parsing(10));
	ft_strlcpy(map->s_path, map_str + i, count + 1);
	if (check_path_ext(map->s_path) == -1
		|| check_path_open(map->s_path) == -1)
		return (print_error_parsing(12));
	map->s = 1;
	*position = i + count;
	return (1);
}
