/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:08:13 by juan-ant          #+#    #+#             */
/*   Updated: 2025/05/23 19:12:23 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3Dexec.h"

void    start_drawing(int pixel, int start, int end, s_exec *exec)
{
    int i;

    i = 0;
    while (i < start)
    {
        mlx_put_pixel(exec->img, pixel, i, 100);
        i ++;
    }
    while (i < end)
    {
        mlx_put_pixel(exec->img, pixel, i, 1666);
        i ++;
    }
    while (i < HEIGHT)
    {
        mlx_put_pixel(exec->img, pixel, i, 50);
        i ++;
    }
}

void    drawmlx(int pixel, double distance, s_exec *exec)
{
    int wallh;
    int start;
    int end;

    if (distance <= 0.01)
        distance = 0.01;
    printf("distance: %f %i\n", distance, pixel);
    wallh = (int)(HEIGHT / distance);
    start = (HEIGHT / 2) - (wallh / 2);
    end = (HEIGHT / 2) + (wallh / 2);
    if (start <= 0)
        start = 1;
    if (end > HEIGHT)
        end = HEIGHT;
    if (start <= 0)
        start = 1;
    if (end > HEIGHT)
        end = HEIGHT;
    start_drawing(pixel, start, end, exec);
}
