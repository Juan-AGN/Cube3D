/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:17:04 by juan-ant          #+#    #+#             */
/*   Updated: 2025/05/23 15:24:04 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3Dexec.h"

void rotate_r(s_exec *exec)
{
    exec->player.ang += 1;
    if (exec->player.ang > 360)
        exec->player.ang = 1;
    init_rays(exec);
}

void rotate_l(s_exec *exec)
{
    exec->player.ang -= 1;
    if (exec->player.ang < 0)
        exec->player.ang = 359;
    init_rays(exec);
}