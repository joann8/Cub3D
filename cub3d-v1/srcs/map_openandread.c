/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_openandread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:44:09 by jacher            #+#    #+#             */
/*   Updated: 2021/01/06 15:33:05 by jacher           ###   ########.fr       */
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
		return (-1);
	bytes = 1;
	count = 0;
	while (bytes)
	{
		bytes = read(fd, buf, 4096);
		if (bytes == -1)
		{
			close(fd); //obligatoire?
			return (-1);
		}
		count += bytes;
	}
	close(fd);
	return (count);
}

int		map_copy_str(char *av, char *map_str)
{
	char	buf[4096];
	int		fd;
	int		bytes;
	int		i;
	int		j;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (-1);
	bytes = 1;
	i = 0;
	while (bytes)
	{
		bytes = read(fd, buf, 4096);
		if (bytes == -1)
			break ;
		j = 0;
		while (j < bytes)
		{
			map_str[i] = buf[j];
			i++;
			j++;
		}
	}
	//map_str[i] = '\0'; //on peut le mettre dans la fonction en mont si besoin
	close(fd);
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
		return (NULL);
	map_str[count] = '\0';
	count = map_copy_str(av, map_str);
	if (count == -1)
	{
		free(map_str);
		return (NULL);
	}
	return (map_str);
}
