/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_checkinputs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:45:46 by jacher            #+#    #+#             */
/*   Updated: 2021/02/10 12:23:22 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		count_bigger_line(char *map_str, int i)
{
	int count;
	int max;

	max = 0;
	while (map_str[i])
	{
		count = 0;
		while (map_str[i] && map_str[i] != '\n')
		{
			count++;
			i++;
		}
		if (count > max)
			max = count;
		i++;
	}
	return (max);
}

int		check_map_inputs_2(char *map_str, int *lines, int i, int mod)
{
	if (map_str[i] == '\0' && (map_str[i - 1] == '0' || map_str[i - 1] == '1'
			|| map_str[i - 1] == '2' || map_str[i - 1] == ' '))
		*lines += 1;
	while (map_str[i] == '\n')
		i++;
	if (map_str[i])
		return (print_error_parsing(6));
	if (mod != 1)
		return (print_error_parsing(8));
	return (1);
}

int		check_map_inputs(char *map_str, int *lines, int i, int mod)
{
	while (map_str[i])
	{
		if (map_str[i] == '\n')
		{
			i++;
			*lines += 1;
		}
		if (map_str[i] == '0' || map_str[i] == '1'
			|| map_str[i] == '2' || map_str[i] == ' ')
			i++;
		else if (map_str[i] == 'N' || map_str[i] == 'S'
					|| map_str[i] == 'E' || map_str[i] == 'W')
		{
			mod++;
			i++;
		}
		else if (map_str[i])
			break ;
	}
	if (check_map_inputs_2(map_str, lines, i, mod) == -1)
		return (-1);
	return (1);
}

int		check_str(char *map_str, int *pos, t_map *map)
{
	int		i;
	int		lines;
	int		col;

	i = *pos;
	lines = 0;
	while (map_str[i] == '\n' && map_str[i])
		i++;
	*pos = i;
	if (check_map_inputs(map_str, &lines, i, 0) == -1)
		return (-1);
	col = count_bigger_line(map_str, i);
	if (col < 3 || lines < 3)
	{
		print_error_parsing(16);
		return (-1);
	}
	map->map_col = col;
	map->map_lin = lines;
	return (1);
}
