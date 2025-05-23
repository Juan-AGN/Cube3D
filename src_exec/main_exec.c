#include "../include/cube3Dexec.h"

void	gameplay(mlx_key_data_t keydata, void *param)
{
	s_exec *exec;

	exec = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(exec->stance);
	else if (keydata.key == MLX_KEY_W && keydata.action != MLX_RELEASE)
		move_up(exec);
	else if (keydata.key == MLX_KEY_S && keydata.action != MLX_RELEASE)
        move_down(exec);
	else if (keydata.key == MLX_KEY_A && keydata.action != MLX_RELEASE)
        move_left(exec);
	else if (keydata.key == MLX_KEY_D && keydata.action != MLX_RELEASE)
        move_right(exec);
	else if (keydata.key == MLX_KEY_Q && keydata.action != MLX_RELEASE)
        rotate_l(exec);
	else if (keydata.key == MLX_KEY_E && keydata.action != MLX_RELEASE)
        rotate_r(exec);
}

void	main_exec(struct s_game_data *cub)
{
    s_exec *exec;
    
    exec = malloc(sizeof(s_exec));
    exec->cub = cub;
    init_player(exec);
    exec->stance = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
    exec->img = mlx_new_image(exec->stance, WIDTH, HEIGHT);
    init_rays(exec);
    mlx_image_to_window(exec->stance, exec->img, 0, 0);
    mlx_key_hook(exec->stance, &gameplay, exec);
	mlx_loop(exec->stance);
}

