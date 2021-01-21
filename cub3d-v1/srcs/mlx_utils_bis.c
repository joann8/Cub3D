/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 13:32:15 by jacher            #+#    #+#             */
/*   Updated: 2021/01/14 17:53:05 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	mlx_draw_line(t_mlx *mlx)
{
	float a;
	float b;
	float count;
	printf("enter draw line\n");
	a = (mlx->ray->y_hit - mlx->player->y) / (mlx->ray->x_hit - mlx->player->x);
	b = mlx->player->y / (mlx->player->x * a);

	printf("a = %f | b = %f\n", a ,b);
	int x1;
	int y1;
	x1 = 0;
	while (x1 < mlx->player->x_max)
	{
		y1 = 0;
		while (y1 < mlx->player->y_max)
		{
			count = a * x1 + b;
			if (y1 - count < 1 && y1 - count > -1)
			{
				if (y1 - mlx->player->y < 30 && y1 - mlx->player->y > -30 && x1 - mlx->player->x < 30 && x1 - mlx->player->x > -30)
				//printf("x1 = %d | y1 = %d\n", x1, y1);
				//printf("***enter if\n");
				my_mlx_pixel_put(mlx, y1, x1, 0x00000000);
			}
			y1++;
		}
		x1++;
	}
	printf("exit draw line\n");
}
/*
void	mlx_draw_line(t_mlx *mlx)
{
	printf("enter draw line\n");
	
	float x;
	float y; 
	float move; 
	float a;
	float b;

	print_player(mlx->player);
	move = mlx->player->speed_walk * mlx->player->dir_walk_bf + mlx->player->speed_walk * mlx->player->dir_walk_lr;
	x = mlx->player->x + cos(mlx->player->dir_ang + deg_to_rad(90) * mlx->player->dir_walk_lr) * move;
	y = mlx->player->y + sin(mlx->player->dir_ang + deg_to_rad(90) * mlx->player->dir_walk_lr) * move;
	my_mlx_pixel_put(mlx, y, x, 0x00000000);
	
	a = (y - mlx->player->y) / (x - mlx->player->x);
	b = mlx->player->y / (mlx->player->x * a);

	printf("a = %f | b = %f\n", a ,b);
	int x1;
	int y1;

	x1 = 0;
	while (x1 < mlx->player->x_max)
	{
		y1 = 0;
		while (y1 < mlx->player->y_max)
		{
			if (y1 == a * x1 + b)
			{
				//printf("x1 = %d | y1 = %d\n", x1, y1);
				//printf("***enter if\n");
				my_mlx_pixel_put(mlx, y1, x1, 0x00000000);
			}
			y1++;
		}
		x1++;
	}
	printf("exit draw line\n");
}
*/
void	mlx_draw_circle(int r, t_mlx *mlx)
{
	int x1;
	int y1;

	//printf("enter draw circle\n");
	x1 = 0;
	while (x1 < mlx->player->x_max)
	{
		y1 = 0;
		while (y1 < mlx->player->y_max)
		{
			if (((mlx->player->x - x1 ) * (mlx->player->x - x1) + (mlx->player->y - y1) * (mlx->player->y - y1)) <= r * r)
			{
			//	printf("x1 = %d | y1 = %d\n", x1, y1);
			//	printf("***enter if\n");
				my_mlx_pixel_put(mlx, y1, x1, 0x00999999);
			}
			y1++;
		}
		x1++;
	}
//	printf("exit draw circle\n");
}
