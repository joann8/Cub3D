/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_nsew.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:08:47 by jacher            #+#    #+#             */
/*   Updated: 2021/01/28 09:32:56 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
//#include "../libft.h"

int		skip_space_folder(char *map_str, int *pos)
{
	int	i;
	int count;
	int dot;

	i = *pos;
	dot = 0;
	while (map_str[i] == ' ')
		i++;
	if (i == *pos) // || (map_str[i] != '.' || map_str[i + 1] != '/'))
		return (-1);
	//else
	//	i += 2;
	*pos = i;
	count = 0;
	while (ft_isprint(map_str[i]) == 1 && map_str[i] != ' ' && map_str[i] != '\n' && map_str[i])
	{
		if (map_str[i] == '.')
			dot++;
		count++;
		i++;
	}
	if (count == 0 || dot > 1)
		return (-1); // chemin vide ou plusieurs extension
	return (count);
	//return (count + 2);
}

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
		return (-1);
	ft_strlcpy(map->no_path, &(map_str[i]), count + 1);
	if (check_path_ext(map->no_path) == -1)// a ajouter quand xpm || check_path_open(map->no_path) == -1) // attention plusieurs points possibles?
		return (-1);
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
		return (-1);
	ft_strlcpy(map->so_path, map_str + i, count + 1);	
	if (check_path_ext(map->so_path) == -1)// a ajouter quand xpm || check_path_open(map->so_path) == -1)
		return (-1);
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
		return (-1);
	ft_strlcpy(map->ea_path, map_str + i, count + 1);
	//printf("EA str = ||%s||\n", map->ea_path);
	//comment verifier que le chemin est correct?	
	if (check_path_ext(map->ea_path) == -1)// a ajouter quand xpm || check_path_open(map->ea_path) == -1)
		return (-1);
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
		return (-1);
	ft_strlcpy(map->we_path, map_str + i, count + 1);
	//printf("WE str = ||%s||\n", map->we_path);
	//comment verifier que le chemin est correct?
	if (check_path_ext(map->we_path) == -1)// a ajouter quand xpm || check_path_open(map->we_path) == -1)
		return (-1);
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
		return (-1);
	ft_strlcpy(map->s_path, map_str + i, count + 1);
	//printf("S str = ||%s||\n", map->s_path);
	//comment verifier que le chemin est correct?	
	if (check_path_ext(map->s_path) == -1)// a ajouter quand xpm || check_path_open(map->s_path) == -1)
		return (-1);
	
	map->s = 1;
	*position = i + count;
	return (1);
}
