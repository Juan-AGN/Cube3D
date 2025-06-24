/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:08:13 by juan-ant          #+#    #+#             */
/*   Updated: 2025/06/23 10:42:51 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3Dexec.h"

uint32_t    transform_color(s_exec *exec, int mode)
{
	t_color touse;
	uint32_t    transformed;

	if (mode == 1)
		touse = exec->cub->ceiling_color;
	else
		touse = exec->cub->floor_color;
	transformed = 0;
	transformed += touse.r << 24;
	transformed += touse.g << 16;
	transformed += touse.b << 8;
	transformed += 255;
	return (transformed);
}

uint32_t    get_texture_pixel(mlx_texture_t *texture, int size, int i, double coord)
{
	unsigned int r;
	unsigned int g;
	unsigned int b;
	uint32_t	img_h;
	uint32_t	img_w;
	uint32_t	pixel;
	uint32_t    transformed;

	img_h = (((texture->height - 1) * i) / size) * texture->width;
	img_w = texture->width - (int)(texture->width * (coord - (int)coord));
	pixel = (img_h + img_w) * texture->bytes_per_pixel;
	r = texture->pixels[pixel];
	g = texture->pixels[pixel + 1];
	b = texture->pixels[pixel + 2];
	transformed = r << 24;
	transformed += g << 16;
	transformed += b << 8;
	transformed += 255;
	return (transformed);
}

uint32_t    texture_pixel(s_ray raytrace, s_exec *exec, int i)
{
	if (raytrace.side == 0 && raytrace.stepx < 0)
		return (get_texture_pixel(exec->we, raytrace.wallh, i - raytrace.start, raytrace.hit));
	else if (raytrace.side == 0 && raytrace.stepx > 0)
		return (get_texture_pixel(exec->ea, raytrace.wallh, i - raytrace.start, raytrace.hit));
	else if (raytrace.side == 1 && raytrace.stepy < 0)
		return (get_texture_pixel(exec->no, raytrace.wallh, i - raytrace.start, raytrace.hit));
	else if (raytrace.side == 1 && raytrace.stepy > 0)
		return (get_texture_pixel(exec->so, raytrace.wallh, i - raytrace.start, raytrace.hit));
	else
		return (transform_color(exec, 1));
}

void    start_drawing(int pixel, int start, int end, s_exec *exec, s_ray raytrace)
{
	int i;

	i = 0;
	while (i < start)
	{
		mlx_put_pixel(exec->img, pixel, i, transform_color(exec, 1));
		i ++;
	}
	while (i < end)
	{
		mlx_put_pixel(exec->img, pixel, i, texture_pixel(raytrace, exec, i));
		i ++;
	}
	while (i < HEIGHT)
	{
		mlx_put_pixel(exec->img, pixel, i, transform_color(exec, 0));
		i ++;
	}
}

void    drawmlx(int pixel, double distance, s_exec *exec, s_ray raytrace)
{
	int start;
	int end;

	if (distance <= 0.01)
		distance = 0.01;
	if (raytrace.side == 0)
		raytrace.hit = raytrace.y + (distance * raytrace.rady);
	else
		raytrace.hit = raytrace.x + (distance * raytrace.radx);
	distance *= sec_transform(raytrace.dir, exec->player.ang);
	raytrace.wallh = (int)(HEIGHT / distance);
	start = (HEIGHT / 2) - (raytrace.wallh / 2);
	raytrace.start = start;
	end = (HEIGHT / 2) + (raytrace.wallh / 2);
	if (start <= 0)
		start = 0;
	if (end > HEIGHT)
		end = HEIGHT;
	start_drawing(pixel, start, end, exec, raytrace);
}
