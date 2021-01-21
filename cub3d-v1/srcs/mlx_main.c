#include <mlx.h>
#include "../cub.h"
#include "../mlx.h"

int mini_map_update(t_mlx *mlx)
{
	int radius;

	radius = 20;
//	printf("enter mini_map_update\n");
	mlx_create_map(mlx);
//	printf("ok\n");
	//mlx_draw_line(mlx);
	//f_update_player(mlx->player, mlx->map_tab, mlx->map);
	mlx_draw_circle(radius, mlx);
//	cast_all_rays(mlx);
//	printf("ok2\n");
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	return(0);
}

int player_move(t_mlx *mlx)
{
//	printf("enter player move\n");
	f_update_player(mlx->player, mlx->map_tab, mlx->map);
//	juste pour afficher minimap
//	mini_map_update(mlx);
	cast_all_rays(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	return(0);
}


int	close_game(t_mlx *mlx)
{
	(void)mlx;
	printf("close game\n");
	close_win(mlx);
	mlx_destroy_window(mlx->ptr, mlx->win);
	return (0);
}

int mlx_main(t_mlx *mlx)
{
	//mlx pointeur
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
		return(-1);
//	printf("ok main 1\n");

/*	//mlx img pour minimap
	mlx->mm_img = mlx_new_image(mlx->ptr, mlx->map->tile_min * mlx->map->map_col, mlx->map->tile_min * mlx->map->map_lin);
	mlx->mm_img_addr = mlx_get_data_addr(mlx->mm_img, &(mlx->mm_img_bits), &(mlx->mm_img_line_length), &(mlx->mm_img_endian));
	//mlx window pour minimap
	mlx->mm_win = mlx_new_window(mlx->ptr, mlx->map->tile_min * mlx->map->map_col, mlx->map->tile_min * mlx->map->map_lin, "Cub3D_map");
	if (mlx->mm_win == NULL)
		return (-1);*/

	//mlx img pour vue
	mlx->img = mlx_new_image(mlx->ptr, mlx->map->r_x, mlx->map->r_y);
//	mlx->img = mlx_new_image(mlx->ptr, mlx->map->tile_min * mlx->map->map_col, mlx->map->tile_min * mlx->map->map_lin);
	mlx->img_addr = mlx_get_data_addr(mlx->img, &(mlx->img_bits), &(mlx->img_line_length), &(mlx->img_endian));
	
//	printf("ok main 2\n");
	//if ac == 3
	//make screen shot avec mlx_create map?
	//mlx window
	mlx->win = mlx_new_window(mlx->ptr, mlx->map->r_x, mlx->map->r_y, "Cub3D_view");
	if (mlx->win == NULL)
		return (-1);
//	printf("ok main 4\n");

	//events
//	mlx_create_map(mlx);
//	printf("ok main 5\n");
	mlx_hook(mlx->win,2, 1, key_press, mlx);
//	printf("ok main 6\n");
	mlx_key_hook(mlx->win, key_release, mlx);
//	printf("ok main 7\n");
	mlx_hook(mlx->win, 17, 1, close_game, mlx);
	mlx_loop_hook(mlx->win, player_move, mlx);
//	mlx_loop_hook(mlx->win, mini_map_update, mlx);
//	printf("ok main 8\n");
//	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	mlx_loop(mlx->ptr);
	return (1);
}
