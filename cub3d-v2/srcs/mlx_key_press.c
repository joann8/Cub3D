#include "../cub.h"
#include<mlx.h>

int key_press(int key, t_data *d)
{
	printf("press key : %d\n", key);
	if (key == 119) //W
		d->player->dir_walk_bf = 1;
	else if (key == 115) //s
		d->player->dir_walk_bf = -1;
	else if (key == 97) //a
		d->player->dir_walk_lr = 1;
	else if (key == 100) //d
		d->player->dir_walk_lr = -1;
	else if (key == 65361) // gauche
		d->player->dir_turn = 1;
	else if (key == 65363)
		d->player->dir_turn = -1;
	else if (key == 65307)
		close_game(d);
	player_move(d);
	//cast_all_rays(mlx);
	return(0);
}

int key_release(int key, t_data *d)
{
	printf("release key : %d\n", key);
	if (key == 119 || key == 13) //W
		d->player->dir_walk_bf = 0;
	else if (key == 115) //s
		d->player->dir_walk_bf = 0;
	else if (key == 97) //a
		d->player->dir_walk_lr = 0;
	else if (key == 100) //d
		d->player->dir_walk_lr = 0;
	else if (key == 65361) // gauche
		d->player->dir_turn = 0;
	else if (key == 65363)
		d->player->dir_turn = 0;
	return (0);
}

