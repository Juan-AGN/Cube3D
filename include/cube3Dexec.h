
#ifndef CUB3DEXEC_H
# define CUB3DEXEC_H

# include <math.h>
# include "cub3D.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define WIDTH 1080
# define HEIGHT 1090
# define WALL 512
# define FOV 60
# define SPEED 0.05
# define ROTATE_SPEED 40

typedef struct s_txtu {
	mlx_texture_t *no_t;
	mlx_texture_t *so_t;
	mlx_texture_t *ea_t;
	mlx_texture_t *we_t;
	} s_txtu;

typedef struct s_plr {
	double 	x;
	double 	y;
	double 	ang;
	} s_plr;

typedef struct s_ray {
	double 	radx;
	double 	rady;
	int		stepx;
	int		stepy;
	double 	deltax;
	double 	deltay;
	double 	distance;
	double 	x;
	double 	y;
	int 	mapx;
	int 	mapy;
	double 	sidex;
	double 	sidey;
	int 	side;
	double	hit;
	double	dir;
	unsigned int		wallh;
	unsigned int 	start;
	} s_ray;

typedef struct s_exec {
	struct s_game_data *cub;
	s_plr		player;
	mlx_t		*stance;
	mlx_image_t *img;
	mlx_texture_t *no;
	mlx_texture_t *we;
	mlx_texture_t *so;
	mlx_texture_t *ea;
	s_ray			moveray;
	} s_exec;


double	sec_transform(double valone, double valtwo);

void    init_rays(s_exec *exec);

void    loop_rays(double ray[3], s_exec *exec);

void    cast_rays(double ray[3], s_exec *exec, int pixel);

void    init_player(s_exec *exec);

void    drawmlx(int pixel, double distance, s_exec *exec, s_ray raytrace);

void	rotate_l(s_exec *exec);

void	rotate_r(s_exec *exec);

void    move_up(s_exec *exec);

void    move_down(s_exec *exec);

void    move_left(s_exec *exec);

void    move_right(s_exec *exec);

s_ray	inicialize_side_step(s_ray raytrace);

s_ray   dda(s_exec *exec, s_ray raytrace);

int    ray_move(double play_rad, s_exec *exec);

void	move_final_calc(s_exec *exec);

int		angle_ifs(int side, double angle);

#endif