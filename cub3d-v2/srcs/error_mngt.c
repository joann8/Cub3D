/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mngt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:42:58 by jacher            #+#    #+#             */
/*   Updated: 2021/02/11 14:54:39 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	print_error_parsing2(int err_num)
{
	if (err_num == 11)
		printf("Parsing: wrong inputs for at least one texture path.\n");
	else if (err_num == 12)
		printf("Parsing: error occurs when opening/reading a texture path.\n");
	else if (err_num == 13)
		printf("Parsing: wrong inputs for resolution.\n");
	else if (err_num == 14)
		printf("Parsing: wrong inputs for floor.\n");
	else if (err_num == 15)
		printf("Parsing: wrong inputs for ceiling.\n");
	else if (err_num == 16)
		printf("Parsing: map is too small.\n");
	else if (err_num == 17)
		printf("Parsing: at least 2 walls have a similar texture.\n");
}

int		print_error_parsing(int err_num)
{
	printf("Error\n");
	if (err_num == 1)
		printf("Wrong number of arguments.\n");
	else if (err_num == 2)
		printf("The 2nd argument is not a .cub.\n");
	else if (err_num == 3)
		printf("The 3rd argument is not valid.\n");
	else if (err_num == 4)
		printf("Parsing: wrong inputs for at least one element.\n");
	else if (err_num == 5)
		printf("Parsing: resolution is too low for the map inputs.\n");
	else if (err_num == 7)
		printf("Parsing: map inputs are incorrect.\n");
	else if (err_num == 8)
		printf("Parsing: player first position is not correct.\n");
	else if (err_num == 9)
		printf("Parsing: opening, reading or closing error with the .cub.\n");
	else if (err_num == 10)
		printf("Parsing: error occurs while allocating memory (malloc).\n");
	else
		print_error_parsing2(err_num);
	return (-1);
}

int		print_error_mlx(int err_num)
{
	printf("Error\n");
	if (err_num == 1)
		printf("Mlx: Connection between software and display failed.\n");
	if (err_num == 2)
		printf("Mlx: Image creation error.\n");
	if (err_num == 3)
		printf("Mlx: Window creation error.\n");
	if (err_num == 4)
		printf("Mlx: error occurs while allocating memory (malloc).\n");
	else
		printf("Error not yet defined.\n");
	return (-1);
}

int		print_error_else(int err_num)
{
	printf("Error\n");
	if (err_num == 1)
		printf("Bmp: Error occurs while creating save.bmp.\n");
	else if (err_num == 2)
		printf("Bmp: Error occur while allocating memory.\n");
	else
		printf("Error not yet defined.\n");
	return (-1);
}
