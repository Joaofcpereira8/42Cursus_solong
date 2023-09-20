/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:34:24 by jofilipe          #+#    #+#             */
/*   Updated: 2023/06/23 15:34:24 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	data_init(t_data *data)
{
	data->x = 0;
	data->y = 0;
	data->plr_x = 0;
	data->plr_y = 0;
	data->ex_x = 0;
	data->ex_y = 0;
	data->fd = 0;
	data->width = 50;
	data->height = 50;
	data->collected = 0;
	data->to_collect = 0;
	data->moves = 0;
	data->direction = 'D';
}

void	info_init(t_info *info)
{
	info->plr = 0;
	info->enmy = 0;
	info->floor = 0;
	info->ex_x = 0;
	info->ex_y = 0;
	info->cltb_av = 0;
	info->cltb_ch = 0;
	info->wall = 0;
	info->ext_av = 0;
	info->ext_ch = 0;
	info->trig = 0;
	info->char_trig = 0;
}
