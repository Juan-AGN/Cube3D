/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:46:03 by juan-ant          #+#    #+#             */
/*   Updated: 2025/05/23 19:16:50 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3Dexec.h"

void    init_rays(s_exec *exec)
{
	double	ray[3];

	printf("start:\n");
	ray[0] = exec->player.ang - ((double)(FOV / 2));
	if (ray[0] < 0)
		ray[0] += 360;
	else if (ray[0] > 360)
		ray[0] -= 360;
	ray[1] = exec->player.x;
	ray[2] = exec->player.y;
	loop_rays(ray, exec);
}

void    loop_rays(double ray[3], s_exec *exec)
{
	int		pixel;
	double	pixfov;

	pixfov = ((float)FOV) / WIDTH;
	pixel = 1;
	while (pixel <= WIDTH)
	{
		ray[0] += pixfov;
		cast_rays(ray, exec, pixel);
		if (ray[0] > 360)
			ray[0] -= 360;
		pixel ++;
	}
}

void    cast_rays(double ray[3], s_exec *exec, int pixel)
{
	s_ray raytrace;

	raytrace.hit = 0;
	raytrace.radx = cos(ray[0] * (3.14159265358979323846 / 180.0));
	raytrace.rady = sin(ray[0] * (3.14159265358979323846 / 180.0));
	raytrace.x = ray[1];
	raytrace.y = ray[2];
	raytrace.mapx = (int)ray[1];
	raytrace.mapy = (int)ray[2];
	raytrace.distance = 0;
	raytrace = dda(exec, raytrace);
	if (raytrace.side == 0)
    	raytrace.distance = raytrace.sidex - raytrace.deltax;
	else
    	raytrace.distance = raytrace.sidey - raytrace.deltay;
	drawmlx(pixel, raytrace.distance, exec);
}

s_ray   dda(s_exec *exec, s_ray raytrace)
{
	raytrace.deltax = fabs(1 / raytrace.radx);
	raytrace.deltay = fabs(1 / raytrace.rady);
	raytrace = inicialize_side_step(raytrace);
	while (raytrace.hit != 1)
	{
		if (raytrace.sidex < raytrace.sidey)
		{
			raytrace.sidex += raytrace.deltax;
			raytrace.mapx += raytrace.stepx;
			raytrace.side = 0;
		}
		else
		{
			raytrace.sidey += raytrace.deltay;
			raytrace.mapy += raytrace.stepy;
			raytrace.side = 1;
		}
		printf("%i, %i\n", raytrace.mapy, raytrace.mapx);
		if (exec->cub->map.grid[(int)raytrace.mapy][(int)raytrace.mapx] == '1')
        	raytrace.hit = 1;
	}
	return (raytrace);
}

s_ray	inicialize_side_step(s_ray raytrace)
{
	if (raytrace.radx < 0)
	{
    	raytrace.stepx = -1;
		raytrace.sidex = (raytrace.x - raytrace.mapx) * raytrace.deltax;
	}
	else
	{
    	raytrace.stepx = 1;
		raytrace.sidex = (raytrace.mapx + 1 - raytrace.x) * raytrace.deltax;
	}
	if (raytrace.rady < 0)
	{
    	raytrace.stepy = -1;
		raytrace.sidey = (raytrace.y - raytrace.mapy) * raytrace.deltay;
	}
	else
	{
    	raytrace.stepy = 1;
		raytrace.sidey = (raytrace.mapy + 1 - raytrace.y) * raytrace.deltay;
	}
	return (raytrace);
}
