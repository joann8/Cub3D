#include <mlx.h>
#include "../cub.h"
#include "../mlx.h"

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

int player_move(t_data *d)
{
//	printf("enter player move\n");
	f_update_player(d);
//juste pour afficher minimap
//	mini_map_update(d);
	cast_all_rays(d);
	mlx_put_image_to_window(d->mlx->ptr, d->mlx->win, d->mlx->img->ptr, 0, 0);
	return(0);
}


int	close_game(t_data *d)
{
	(void)d;
	printf("close game\n");
	close_win(d->mlx->ptr);
	mlx_destroy_window(d->mlx->ptr, d->mlx->win);
	return (0);
}

int mlx_main(t_data *d)
{
	t_mlx m;
	t_img img;

	d->mlx = &m;
	d->mlx->img =&img;
	//mlx pointeur
	d->mlx->ptr = mlx_init();
	if (d->mlx->ptr == NULL)
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
	d->mlx->img->ptr = mlx_new_image(d->mlx->ptr, d->map->r_x, d->map->r_y);
//	mlx->img = mlx_new_image(mlx->ptr, mlx->map->tile_min * mlx->map->map_col, mlx->map->tile_min * mlx->map->map_lin);
	d->mlx->img->addr = mlx_get_data_addr(d->mlx->img->ptr, &(d->mlx->img->bits), &(d->mlx->img->length), &(d->mlx->img->endian));
	
//	printf("ok main 2\n");
	//if ac == 3
	//make screen shot avec mlx_create map?
	//mlx window
	d->mlx->win = mlx_new_window(d->mlx->ptr, d->map->r_x, d->map->r_y, "Cub3D_view");
	if (d->mlx->win == NULL)
		return (-1);
//	printf("ok main 4\n");

	//events
//	mlx_create_map(mlx);
//	printf("ok main 5\n");
	mlx_hook(d->mlx->win,2, 1, key_press, d);
//	printf("ok main 6\n");
	mlx_key_hook(d->mlx->win, key_release, d);
//	printf("ok main 7\n");
	mlx_hook(d->mlx->win, 17, 1, close_game, d);
	mlx_loop_hook(d->mlx->win, player_move, d);
//	mlx_loop_hook(mlx->win, mini_map_update, mlx);
//	printf("ok main 8\n");
//	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	mlx_loop(d->mlx->ptr);
	return (1);
}
