
#ifndef CUB3DEXEC_H
# define CUB3DEXEC_H

# include "cub3D.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_txtu {
	mlx_texture_t *no_t;
	mlx_texture_t *so_t;
	mlx_texture_t *ea_t;
	mlx_texture_t *we_t;
	} s_txtu;

typedef struct s_plr {
	int 	x;
	int 	y;
	double 	angle;
	} s_plr;

typedef struct s_exec {
	struct s_game_data *cub;
	mlx_t		*stance;
	} s_exec;

#endif