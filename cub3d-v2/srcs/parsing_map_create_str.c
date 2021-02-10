/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_openandread.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:44:09 by jacher            #+#    #+#             */
/*   Updated: 2021/02/10 12:38:06 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		map_count_char(char *av)
{
	char	buf[4096];
	int		fd;
	int		bytes;
	int		count;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (print_error_parsing(9));
	bytes = 1;
	count = 0;
	while (bytes)
	{
		bytes = read(fd, buf, 4096);
		if (bytes == -1)
		{
			close(fd);
			return (print_error_parsing(9));
		}
		count += bytes;
	}
	if (close(fd) == -1)
		return (print_error_parsing(9));
	return (count);
}

void	copy_function(char *map_str, int *pos, char *buf, int bytes)
{
	int j;
	int i;

	j = 0;
	i = *pos;
	while (j < bytes)
	{
		map_str[i] = buf[j];
		i++;
		j++;
	}
	*pos = i;
}

int		map_copy_str(char *av, char *map_str)
{
	char	buf[4096];
	int		fd;
	int		bytes;
	int		i;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (print_error_parsing(9));
	bytes = 1;
	i = 0;
	while (bytes)
	{
		bytes = read(fd, buf, 4096);
		if (bytes == -1)
		{
			print_error_parsing(9);
			break ;
		}
		copy_function(map_str, &i, buf, bytes);
	}
	if (close(fd) == -1)
		return (print_error_parsing(9));
	return (bytes);
}

char	*map_create_str(char *av)
{
	int		count;
	char	*map_str;

	if (check_arg1(av) == -1)
		return (NULL);
	count = map_count_char(av);
	if (count == -1)
		return (NULL);
	map_str = malloc(sizeof(char) * (count + 1));
	if (map_str == NULL)
	{
		print_error_parsing(10);
		return (NULL);
	}
	map_str[count] = '\0';
	count = map_copy_str(av, map_str);
	if (count == -1)
	{
		free(map_str);
		return (NULL);
	}
	return (map_str);
}
