#include "../include/cube3Dexec.h"

void	gameplay( void *param)
{
	s_exec *exec;

	exec = param;
	if (mlx_is_key_down(exec->stance, MLX_KEY_ESCAPE))
		mlx_close_window(exec->stance);
	if (mlx_is_key_down(exec->stance, MLX_KEY_W))
		move_up(exec);
	if (mlx_is_key_down(exec->stance, MLX_KEY_S))
		move_down(exec);
	if (mlx_is_key_down(exec->stance, MLX_KEY_A))
		move_left(exec);
	if (mlx_is_key_down(exec->stance, MLX_KEY_D))
		move_right(exec);
	if (mlx_is_key_down(exec->stance, MLX_KEY_Q))
		rotate_l(exec);
	if (mlx_is_key_down(exec->stance, MLX_KEY_E))
		rotate_r(exec);
	 init_rays(exec);
}

void	get_images(s_exec *exec)
{
	exec->we = mlx_load_png(exec->cub->textures.we_path);
	exec->ea = mlx_load_png(exec->cub->textures.ea_path);
	exec->no = mlx_load_png(exec->cub->textures.no_path);
	exec->so = mlx_load_png(exec->cub->textures.so_path);
}

void	main_exec(struct s_game_data *cub)
{
    s_exec *exec;
    
    exec = malloc(sizeof(s_exec));
    exec->cub = cub;
	get_images(exec);
    init_player(exec);
	mlx_set_setting(MLX_STRETCH_IMAGE,true);
    exec->stance = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
    exec->img = mlx_new_image(exec->stance, WIDTH, HEIGHT);
    init_rays(exec);
    mlx_image_to_window(exec->stance, exec->img, 0, 0);
    mlx_loop_hook(exec->stance, &gameplay, exec);
	mlx_loop(exec->stance);
}

