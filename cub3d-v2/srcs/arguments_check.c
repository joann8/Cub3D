/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:51:28 by jacher            #+#    #+#             */
/*   Updated: 2021/02/10 18:49:28 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		check_arg2(char *av)
{
	int		size;

	size = ft_strlen(av);
	if (size != 6)
		return (-1);
	if (av[0] == '-' && av[1] == '-' && av[2] == 's' && av[3] == 'a'
			&& av[4] == 'v' && av[5] == 'e' && av[6] == '\0')
		return (1);
	return (-1);
}

int		check_arg1(char *av)
{
	int		size;
	int		dot;
	int		i;

	size = ft_strlen(av);
	dot = 0;
	i = 0;
	while (av[i])
	{
		if (av[i] == '.')
			dot++;
		i++;
	}
	if (dot != 1)
		return (print_error_parsing(2));
	if (size < 5)
		return (print_error_parsing(2));
	if (av[size - 4] == '.' && av[size - 3] == 'c'
			&& av[size - 2] == 'u' && av[size - 1] == 'b')
		return (1);
	return (-1);
}

int		check_arg(int ac, char **av)
{
	if (ac < 2 || ac > 3)
	{
		print_error_parsing(1);
		return (-1);
	}
	else
	{
		if (check_arg1(av[1]) == -1)
		{
			print_error_parsing(2);
			return (-1);
		}
		if (ac == 3)
		{
			if (check_arg2(av[2]) == -1)
			{
				print_error_parsing(3);
				return (-1);
			}
		}
	}
	return (ac);
}

int		check_path_ext(char *str)
{
	int		size;
	int		dot;
	int		i;

	size = ft_strlen(str);
	dot = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '.' && i != 0)
			dot++;
		i++;
	}
	if (dot != 1)
		return (-1);
	if (size < 5)
		return (-1);
	if (str[size - 4] == '.' && str[size - 3] == 'x'
			&& str[size - 2] == 'p' && str[size - 1] == 'm')
		return (1);
	return (-1);
}

int		check_path_open(char *str)
{
	int		fd;
	int		bytes;
	char	buf[4096];

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (-1);
	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, buf, 4096);
		if (bytes == -1)
			return (-1);
	}
	if (close(fd) == -1)
		return (-1);
	return (1);
}
