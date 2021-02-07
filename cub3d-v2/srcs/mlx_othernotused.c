#include<mlx.h>
#include "../cub.h"

int mini_map_update(t_data *d)
{
	int radius;

	radius = 20;
//	printf("enter mini_map_update\n");
	mlx_create_map(d);
//	printf("ok\n");
	//mlx_draw_line(mlx);
	//f_update_player(mlx->player, mlx->map_tab, mlx->map);
	mlx_draw_circle(radius, d);
//	cast_all_rays(mlx);
//	printf("ok2\n");
	mlx_put_image_to_window(d->mlx->ptr, d->mlx->win, d->mlx->img->ptr, 0, 0);
	return(0);
}

void	mlx_create_map(t_data *d)
{
	unsigned int i;
	unsigned int j;
	int x;
	int y;
	int res_x;
	int res_y;

	res_x = d->map->r_x / 15;
	res_y = d->map->r_y / 15;
//	printf("enter create map\n");
	i = 0;
	x = i / d->map->tile_lin;
	while (x < d->map->map_lin && d->map_tab[x])
	{
		//printf("tour [%d][%d]\n", i, j);
		j = 0;
		y = j / d->map->tile_col;
		while (y < d->map->map_col && d->map_tab[x][y])
		{
		
		//	printf("map_col = %d | map->tile col = %d\nmap_lin = %d | map->tile_lin = %d \n", mlx->map->map_col, mlx->map->tile_col, mlx->map->map_lin,mlx->map->tile_lin);
		//	printf("tour [%d][%d]\n", i, j);
		//	printf("map_tab[%d][%d] = %c\n", x, y, mlx->map_tab[x][y]);
			if (d->map_tab[x][y] == 'x')
				my_mlx_pixel_put(d, j ,i, 0x00FF0000);
			else if (d->map_tab[x][y] == '1')
				my_mlx_pixel_put(d, j, i, 0x0000FF00);
			else if (d->map_tab[x][y] == '0')
				my_mlx_pixel_put(d, j, i, 0x00FFFFFF);
			else if (d->map_tab[x][y] == '2')
				my_mlx_pixel_put(d, j, i, 0x000000FF);
			else
				my_mlx_pixel_put(d, i, j, 0x00FF0000);
			j++;
			y = (j + res_y) / d->map->tile_col;
			
		}
		i++;
		x = (i + res_x) / d->map->tile_lin;
	}
//	printf("exit with success\n");
}

/*
void	mlx_draw_line(t_data *d)
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
}*/
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
void	mlx_draw_circle(int r, t_data *d)
{
	int x1;
	int y1;

	//printf("enter draw circle\n");
	x1 = 0;
	while (x1 < d->player->x_max)
	{
		y1 = 0;
		while (y1 < d->player->y_max)
		{
			if (((d->player->x - x1 ) * (d->player->x - x1) + (d->player->y - y1) * (d->player->y - y1)) <= r * r)
			{
			//	printf("x1 = %d | y1 = %d\n", x1, y1);
			//	printf("***enter if\n");
				my_mlx_pixel_put(d, y1, x1, 0x00999999);
			}
			y1++;
		}
		x1++;
	}
//	printf("exit draw circle\n");
}

