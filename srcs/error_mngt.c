/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:42:58 by jacher            #+#    #+#             */
/*   Updated: 2021/01/07 13:54:53 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	print_error_msg(int err_num)
{
	write(2, "Error\n", 6);
	//ouverture du fichier
	if (err_num == 1)
		write(2, "Missing 1st argument.\n", 22); 
	else if (err_num == 2)
		write(2, "1st argument extension is not a .cub.\n",38);
	else if (err_num == 3)
		write(2, "Error occurs while opening or reading the file.\n", 48); 
	else if (err_num == 4)
		write(2, "Wrong inputs for IDs.\n", 22);
	else if (err_num == 5)
		write(2, "Missing ID.\n", 12);		
	else if (err_num == 6)
		write(2, "Wrong inputs for the scene.\n", 28);
	else if (err_num == 7)
		write(2, "Map not surronded by walls.\n", 28);
	else if (err_num == 8)
		write(2, "Several first position for the player.\n", 39);		
	else if (err_num == 9)
		write(2, "No first position for the player.\n", 34);		
	else if (err_num == 10)
		write(2, "Error occurs while allocating memory.\n", 38);
	else
		write(2, "Error not yet defined.\n", 23);
	return ;
}
