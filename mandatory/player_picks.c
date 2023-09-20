/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_picks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:31:16 by jofilipe          #+#    #+#             */
/*   Updated: 2023/07/06 12:31:16 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	plr_picks_up(t_data *data)
{
	static int	i;

	if (i == 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->playerw_img[0], (data->plr_x * 50), (data->plr_y * 50));
	}
	else if (i == 30000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->playerw_img[1], (data->plr_x * 50), (data->plr_y * 50));
	}
	else if (i == 60000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->playerw_img[0], (data->plr_x * 50), (data->plr_y * 50));
		i = 0;
	}
	i++;
}

void	plr_picks_down(t_data *data)
{
	static int	i;

	if (i == 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->players_img[0], (data->plr_x * 50), (data->plr_y * 50));
	}
	else if (i == 30000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->players_img[1], (data->plr_x * 50), (data->plr_y * 50));
	}
	else if (i == 60000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->players_img[0], (data->plr_x * 50), (data->plr_y * 50));
		i = 0;
	}
	i++;
}

void	plr_picks_left(t_data *data)
{
	static int	i;

	if (i == 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->playera_img[0], (data->plr_x * 50), (data->plr_y * 50));
	}
	else if (i == 30000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->playera_img[1], (data->plr_x * 50), (data->plr_y * 50));
	}
	else if (i == 60000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->playera_img[0], (data->plr_x * 50), (data->plr_y * 50));
		i = 0;
	}
	i++;
}

void	plr_picks_right(t_data *data)
{
	static int	i;

	if (i == 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->playerd_img[0], (data->plr_x * 50), (data->plr_y * 50));
	}
	else if (i == 30000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->playerd_img[1], (data->plr_x * 50), (data->plr_y * 50));
	}
	else if (i == 60000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->playerd_img[0], (data->plr_x * 50), (data->plr_y * 50));
		i = 0;
	}
	i++;
}
