/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mngt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:42:58 by jacher            #+#    #+#             */
/*   Updated: 2021/02/07 19:21:39 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	print_error_parsing(int err_num)
{
	printf("Error parsing\n");
	//ouverture du fichier
	if (err_num == 1)
		printf("Missing 1st argument.\n"); 
	else if (err_num == 2)
		printf("1st argument extension is not a .cub.\n");
	else if (err_num == 3)
		printf("Error occurs while opening or reading the file.\n"); 
	else if (err_num == 4)
		printf("Wrong inputs for IDs.\n");
	else if (err_num == 5)
		printf("Missing elements.\n");		
	else if (err_num == 6)
		printf("Wrong inputs for the scene.\n");
	else if (err_num == 7)
		printf("Map not surronded by walls.\n");
	else if (err_num == 8)
		printf("Several first position for the player.\n");		
	else if (err_num == 9)
		printf("No first position for the player.\n");		
	else if (err_num == 10)
		printf("Error occurs while allocating memory.\n");	
	else if (err_num == 11)
		printf("Wrong inputs for texture path.\n");	
	else if (err_num == 12)
		printf("Error occurs when opening texture path.\n");
	else if (err_num == 13)
		printf("Wrong inputs for color (floor or ceiling).\n");	
	else if (err_num == 14)
		printf("Negative value for color (floor or ceiling).\n");	
	else
		printf("Error not yet defined.\n");
	return (-1);
}

int	print_error_mlx(int err_num, t_data *d)
{
	close_game(d);
	printf("Error Software\n");
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
	
