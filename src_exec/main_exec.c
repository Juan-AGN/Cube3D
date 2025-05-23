#include "../include/cube3Dexec.h"

void	main_exec(struct s_game_data *cub)
{
    s_exec *exec;
    
    exec = malloc(sizeof(s_exec));
    exec->cub = cub;
	exec->stance = mlx_init((1000) * 64,
			1000, "Cub3D", false);
	mlx_loop(exec->stance);
}