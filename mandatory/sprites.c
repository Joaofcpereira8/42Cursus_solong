/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:51:39 by jofilipe          #+#    #+#             */
/*   Updated: 2023/07/07 15:37:59 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moves(t_data *data, int key)
{
	if (key == XK_w && check_mov(data, data->plr_x, data->plr_y - 1))
	{
		data->direction = 'U';
		data->map_dup[data->plr_y][data->plr_x] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->floor_img, (data->plr_x * 50), (data->plr_y * 50));
		data->plr_y--;
		data->map_dup[data->plr_y][data->plr_x] = 'P';
	}
	else if (key == XK_a && check_mov(data, data->plr_x - 1, data->plr_y))
	{
		data->direction = 'L';
		data->map_dup[data->plr_y][data->plr_x] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->floor_img, (data->plr_x * 50), (data->plr_y * 50));
		data->plr_x--;
		data->map_dup[data->plr_y][data->plr_x] = 'P';
	}
	else
		moves2(data, key);
}

void	moves2(t_data *data, int key)
{
	if (key == XK_d && check_mov(data, data->plr_x + 1, data->plr_y))
	{
		data->direction = 'R';
		data->map_dup[data->plr_y][data->plr_x] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->floor_img, (data->plr_x * 50), (data->plr_y * 50));
		data->plr_x++;
		data->map_dup[data->plr_y][data->plr_x] = 'P';
	}
	else if (key == XK_s && check_mov(data, data->plr_x, data->plr_y + 1))
	{
		data->direction = 'D';
		data->map_dup[data->plr_y][data->plr_x] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->floor_img, (data->plr_x * 50), (data->plr_y * 50));
		data->plr_y++;
		data->map_dup[data->plr_y][data->plr_x] = 'P';
	}
}

int	check_mov(t_data *data, int x, int y)
{
	if (data->map_dup[y][x] == '1' || data->map_dup[y][x] == 'E')
		return (0);
	data->moves++;
	ft_printf ("Moves: %d\n", data->moves);
	fps(data, x, y);
	if (data->map_dup[y][x] == 'C' && data->collected != data->to_collect)
	{
		fps(data, x, y);
		data->collected++;
		data->map_dup[y][x] = '0';
		fps(data, x, y);
		if (data->collected == data->to_collect)
		{
			data->map_dup[data->ex_y][data->ex_x] = 'e';
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->exit_img[1], (data->ex_x * 50), (data->ex_y * 50));
		}
	}
	else if (data->map_dup[y][x] == 'e')
	{
		fps(data, x, y);
		ft_printf("Congrats! You've won the game!\n");
		end_game(data);
	}
	return (1);
}

int	update(t_data *data)
{
	if (data->direction == 'U')
		plr_picks_up(data);
	else if (data->direction == 'R')
		plr_picks_right(data);
	else if (data->direction == 'L')
		plr_picks_left(data);
	else if (data->direction == 'D')
		plr_picks_down(data);
	return (0);
}

void	fps(t_data *data, int x, int y)
{
	if (data->direction == 'U')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->playerw_img[0], (x * 50), (y * 50));
	else if (data->direction == 'R')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->playerd_img[0], (x * 50), (y * 50));
	else if (data->direction == 'L')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->playera_img[0], (x * 50), (y * 50));
	else if (data->direction == 'D')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->players_img[0], (x * 50), (y * 50));
}
