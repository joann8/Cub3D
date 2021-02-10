/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mngt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:42:58 by jacher            #+#    #+#             */
/*   Updated: 2021/02/10 12:45:45 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	print_error_parsing(int err_num)
{
	printf("Error\n");
	//ouverture du fichier
	if (err_num == 1)
		printf("Missing 1st argument.\n"); 
	else if (err_num == 2)
		printf("1st argument extension is not a .cub.\n");
	else if (err_num == 3)
		printf("Error occurs while opening or reading the file.\n"); 
	else if (err_num == 4) //
		printf("Wrong inputs for at least one element.\n");
	else if (err_num == 5)
		printf("Missing elements.\n");		
	else if (err_num == 6)
		printf("Wrong inputs for the scene.\n");
	else if (err_num == 7) //
		printf("Map inputs are incorrect.\n");
	else if (err_num == 8) //
		printf("Player first position is not correct.\n");		
	else if (err_num == 9) //
		printf("Error occurs while opening/reading/closing the .cub.\n"); 
	
	else if (err_num == 10)//
		printf("Error occurs while allocating memory.\n");	
	else if (err_num == 11) //
		printf("Wrong inputs for at least one texture path.\n");	
	else if (err_num == 12) //
		printf("Error occurs when opening/reading a texture path.\n");
	else if (err_num == 13) //
		printf("Wrong inputs for resolution.\n");
	else if (err_num == 14) //
		printf("Wrong inputs for floor.\n");
	else if (err_num == 15) //
		printf("Wrong inputs for ceiling.\n");	
	else if (err_num == 16) //
		printf("Map is too small.\n");	
	else if (err_num == 17) //
		printf("At least 2 walls have a similar texture.\n");	
	else
		printf("Error not yet defined.\n");
	return (-1);
}

int	print_error_mlx(int err_num)
{
	printf("Error\n");
	if (err_num == 1)
		printf("Connection between software and display failed.\n");	
	if (err_num == 2)
		printf("Image creation error.\n");	
	if (err_num == 3)
		printf("Window creation error.\n");	
	else
		printf("Error not yet defined.\n");
	return(-1);
}

int	print_error_else(int err_num)
{
	printf("Error\n");
	if (err_num == 1)
		printf("Error occurs while creating save.bmp.\n");	
	else if (err_num == 2)
		printf("Error occur while allocating memory for saving bmp.\n");	
	else
		printf("Error not yet defined.\n");
	return(-1);
}
	
	
