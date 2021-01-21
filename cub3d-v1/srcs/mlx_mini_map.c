#include<mlx.h>
#include "../cub.h"

void	mlx_create_map(t_mlx *mlx)
{
	unsigned int i;
	unsigned int j;
	int x;
	int y;

//	printf("enter create map\n");
	i = 0;
	x = i / mlx->map->tile_lin;
	while (x < mlx->map->map_lin && mlx->map_tab[x])
	{
		//printf("tour [%d][%d]\n", i, j);
		j = 0;
		y = j / mlx->map->tile_col;
		while (y < mlx->map->map_col && mlx->map_tab[x][y])
		{
		
		//	printf("map_col = %d | map->tile col = %d\nmap_lin = %d | map->tile_lin = %d \n", mlx->map->map_col, mlx->map->tile_col, mlx->map->map_lin,mlx->map->tile_lin);
		//	printf("tour [%d][%d]\n", i, j);
		//	printf("map_tab[%d][%d] = %c\n", x, y, mlx->map_tab[x][y]);
			if (mlx->map_tab[x][y] == 'x')
				my_mlx_pixel_put(mlx, j ,i, 0x00FF0000);
			else if (mlx->map_tab[x][y] == '1')
				my_mlx_pixel_put(mlx, j, i, 0x0000FF00);
			else if (mlx->map_tab[x][y] == '0')
				my_mlx_pixel_put(mlx, j, i, 0x00FFFFFF);
			else if (mlx->map_tab[x][y] == '2')
				my_mlx_pixel_put(mlx, j, i, 0x000000FF);
			else
				my_mlx_pixel_put(mlx, i, j, 0x00FF0000);
			j++;
			y = j / mlx->map->tile_col;
			
		}
		i++;
		x = i / mlx->map->tile_lin;
	}
//	printf("exit with success\n");
}
