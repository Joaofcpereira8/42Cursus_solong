/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:27:05 by jofilipe          #+#    #+#             */
/*   Updated: 2023/06/22 12:27:05 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_checker(t_info *info, t_data *data, int x, int y)
{
	info->plr++;
	data->plr_x = x;
	data->plr_y = y;
}

void	wall_checker(t_info *info, t_data *data, int x, int y)
{
	if (data->map_dup[y][x] == '1')
		info->wall++;
	else
		info->trig = -1;
}

void	char_checker(t_info *info, char c)
{
	if (c != 'C' && c != 'E' && c != 'P' && c != '1' && c != '0')
		info->char_trig = -1;
}

int	checker(t_info *info, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y <= data->y)
	{
		x = 0;
		while (x < data->x)
		{
			if ((y == 0 || y == data->y) || (x == 0 || x == data->x - 1))
				wall_checker(info, data, x, y);
			else if (data->map_dup[y][x] == 'C')
				info->cltb_av++;
			else if (data->map_dup[y][x] == 'E')
				info->ext_av++;
			else if (data->map_dup[y][x] == 'P')
				player_checker(info, data, x, y);
			else
				char_checker(info, data->map_dup[y][x]);
			x++;
		}
		y++;
	}
	data->to_collect = info->cltb_av;
	return (error_print(info, data));
}

void	exit_checker(t_info *info, int x, int y)
{
	info->ext_ch++;
	info->ex_x = x;
	info->ex_y = y;
}
