/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:43:01 by juan-ant          #+#    #+#             */
/*   Updated: 2025/05/23 16:52:43 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3Dexec.h"

void    init_player(s_exec *exec)
{
    if (exec->cub->player.dir == 'S')
        exec->player.ang = 90;
    else if (exec->cub->player.dir == 'E')
        exec->player.ang = 0;
    else if (exec->cub->player.dir == 'W')
        exec->player.ang = 180;
    else if (exec->cub->player.dir == 'N')
        exec->player.ang = 270;
    exec->player.x = (double) exec->cub->player.x;
    exec->player.y = (double) exec->cub->player.y;
}

void    move_up(s_exec *exec)
{
    double radx;
	double rady;
    double to_movex;
	double to_movey;

    radx = cos(exec->player.ang * (3.14159265358979323846 / 180.0));
	rady = sin(exec->player.ang * (3.14159265358979323846 / 180.0));
    to_movey = exec->player.y + SPEED * rady;
    to_movex = exec->player.x + SPEED * radx;
    if ((int)(to_movex >= exec->cub->map.width) || (int)(to_movex) <= 0)
        return ;
    if ((int)(to_movey >= exec->cub->map.height) || (int)(to_movey) <= 0)
        return ;
    if (exec->cub->map.grid[((int)(to_movey))]
        [((int)to_movex)] != '1')
    {
        exec->player.y = to_movey;
        exec->player.x = to_movex;
    }
    init_rays(exec);
}

void    move_down(s_exec *exec)
{
    double radx;
	double rady;
    double to_movex;
	double to_movey;

    radx = cos((exec->player.ang - 180)* (3.14159265358979323846 / 180.0));
	rady = sin((exec->player.ang - 180) * (3.14159265358979323846 / 180.0));
    to_movey = exec->player.y + SPEED * rady;
    to_movex = exec->player.x + SPEED * radx;
    if ((int)(to_movex >= exec->cub->map.width) || (int)(to_movex) <= 0)
        return ;
    if ((int)(to_movey >= exec->cub->map.height) || (int)(to_movey) <= 0)
        return ;
    if (exec->cub->map.grid[((int)(to_movey))]
        [((int)to_movex)] != '1')
    {
        exec->player.y = to_movey;
        exec->player.x = to_movex;
    }
    init_rays(exec);
}

void    move_left(s_exec *exec)
{
    double radx;
	double rady;
    double to_movex;
	double to_movey;

    radx = cos((exec->player.ang - 90) * (3.14159265358979323846 / 180.0));
	rady = sin((exec->player.ang - 90) * (3.14159265358979323846 / 180.0));
    to_movey = exec->player.y + SPEED * rady;
    to_movex = exec->player.x + SPEED * radx;
    if ((int)(to_movex >= exec->cub->map.width) || (int)(to_movex) <= 0)
        return ;
    if ((int)(to_movey >= exec->cub->map.height) || (int)(to_movey) <= 0)
        return ;
    if (exec->cub->map.grid[((int)(to_movey))]
        [((int)to_movex)] != '1')
    {
        exec->player.y = to_movey;
        exec->player.x = to_movex;
    }
    init_rays(exec);
}

void   move_right(s_exec *exec)
{
    double radx;
	double rady;
    double to_movex;
	double to_movey;

    radx = cos((exec->player.ang + 90) * (3.14159265358979323846 / 180.0));
	rady = sin((exec->player.ang + 90) * (3.14159265358979323846 / 180.0));
    to_movey = exec->player.y + SPEED * rady;
    to_movex = exec->player.x + SPEED * radx;
    if ((int)(to_movex >= exec->cub->map.width) || (int)(to_movex) <= 0)
        return ;
    if ((int)(to_movey >= exec->cub->map.height) || (int)(to_movey) <= 0)
        return ;
    if (exec->cub->map.grid[((int)(to_movey))]
        [((int)to_movex)] != '1')
    {
        exec->player.y = to_movey;
        exec->player.x = to_movex;
    }
    init_rays(exec);
}