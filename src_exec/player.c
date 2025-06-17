/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:43:01 by juan-ant          #+#    #+#             */
/*   Updated: 2025/06/16 19:16:53 by juan-ant         ###   ########.fr       */
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
    if (ray_move(exec->player.ang, exec) != 1)
        return ;
    move_final_calc(exec);
}

void    move_down(s_exec *exec)
{
    if (ray_move(exec->player.ang - 180, exec) != 1)
        return ;
    move_final_calc(exec);
}

void    move_left(s_exec *exec)
{
    if (ray_move(exec->player.ang - 90, exec) != 1)
        return ;
    move_final_calc(exec);
}

void   move_right(s_exec *exec)
{
    if (ray_move(exec->player.ang + 90, exec) != 1)
        return ;
    move_final_calc(exec);
}