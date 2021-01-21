#include "../cub.h"
#include<mlx.h>

int key_press(int key, t_mlx *mlx)
{
	printf("press key : %d\n", key);
	if (key == 119) //W
		mlx->player->dir_walk_bf = 1;
	else if (key == 115) //s
		mlx->player->dir_walk_bf = -1;
	else if (key == 97) //a
		mlx->player->dir_walk_lr = 1;
	else if (key == 100) //d
		mlx->player->dir_walk_lr = -1;
	else if (key == 65361) // gauche
		mlx->player->dir_turn = 1;
	else if (key == 65363)
		mlx->player->dir_turn = -1;
	else if (key == 65307)
		close_game(mlx);
	player_move(mlx);
	//cast_all_rays(mlx);
	return(0);
}

int key_release(int key, t_mlx *mlx)
{
	printf("release key : %d\n", key);
	if (key == 119 || key == 13) //W
		mlx->player->dir_walk_bf = 0;
	else if (key == 115) //s
		mlx->player->dir_walk_bf = 0;
	else if (key == 97) //a
		mlx->player->dir_walk_lr = 0;
	else if (key == 100) //d
		mlx->player->dir_walk_lr = 0;
	else if (key == 65361) // gauche
		mlx->player->dir_turn = 0;
	else if (key == 65363)
		mlx->player->dir_turn = 0;
	return (0);
}

